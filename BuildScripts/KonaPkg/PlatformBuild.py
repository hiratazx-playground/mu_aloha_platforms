# @file
# Script to Build UEFI firmware
#
# Copyright (c) Microsoft Corporation.
# SPDX-License-Identifier: BSD-2-Clause-Patent
##
import logging
import os

from BuildScripts import mkbootimg

## woa-msmnile patch start
SiliconName = "Sm8250"
PlatformName = "Kona"
PackageName = f"{PlatformName}Pkg"
SecureBoot = False
## woa-msmnile patch end

from edk2toolext.environment import shell_environment
from edk2toolext.environment.uefi_build import UefiBuilder
from edk2toolext.invocables.edk2_platform_build import BuildSettingsManager
from edk2toolext.invocables.edk2_pr_eval import PrEvalSettingsManager
from edk2toolext.invocables.edk2_setup import (RequiredSubmodule,
                                               SetupSettingsManager)
from edk2toolext.invocables.edk2_update import UpdateSettingsManager
from edk2toolext.invocables.edk2_parse import ParseSettingsManager

def makeAndroidImage(outputbin_dir, output_dir, root_dir, device_name, dtb_name) :
    bootpayload_path = os.path.join(output_dir, 'bootpayload.bin')
    output_path = os.path.join(output_dir, device_name + '.img')
    fd_path = os.path.join(outputbin_dir, 'FV', 'SM8250_EFI.fd')
    bootshim_path = os.path.join(root_dir, 'BootShim', 'BootShim.bin')
    dtb_path = os.path.join(root_dir, "Platforms", "KonaPkg", "Device", device_name, 'DeviceTreeBlob', 'Android', 'android-' + dtb_name)

    logging.info("Generating bootpayload.bin")

    '''
      Payload:
        | BootShim.bin | SM8250_EFI.fd |
    '''
    with open(bootpayload_path, 'wb') as f:
        logging.info("Writing UEFI...")
        data = bytes()

        with open(bootshim_path, 'rb') as bootshim_file:
            data += bootshim_file.read()

        with open(fd_path, 'rb') as fd:
            data += fd.read()
            f.write(data)


    logging.info("Writing " + device_name + '.img')

    mkbootimg.main([
        "--kernel", bootpayload_path,
        "-o", output_path,
        "--ramdisk", "./ImageResources/emptyramdisk",
        "--pagesize", "4096",
        "--header_version", "2",
        "--cmdline", "console=ttyMSM0,115200n8 earlycon=msm_geni_serial,0xa90000 androidboot.hardware=qcom androidboot.console=ttyMSM0 androidboot.memcg=1 lpm_levels.sleep_disabled=1 video=vfb:640x400,bpp=32,memsize=3072000 msm_rtb.filter=0x237 service_locator.enable=1 androidboot.usbcontroller=a600000.dwc3 swiotlb=2048 loop.max_part=7 cgroup.memory=nokmem,nosocket reboot=panic_warm buildvariant=userdebug",
        "--dtb", dtb_path,
        "--base", "0x0",
        "--os_version", "10.0.0",
        "--os_patch_level", "2019-11-01",
        "--second_offset", "0xf00000"
    ])

# ####################################################################################### #
    #                                Common Configuration                                     #
    # ####################################################################################### #
class CommonPlatform:
    ''' Common settings for this platform.  Define static data here and use
        for the different parts of stuart
    '''
## woa-msmnile patch start
    PackagesSupported = (PackageName,)
## woa-msmnile patch end
    ArchSupported = ("AARCH64",)
    TargetsSupported = ("DEBUG", "RELEASE", "NOOPT")
    Scopes = (PlatformName, 'gcc_aarch64_linux', 'edk2-build', 'cibuild', 'configdata')
    WorkspaceRoot = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    PackagesPath = (
        "Platforms",
        "MU_BASECORE",
        "Common/MU",
        "Common/MU_TIANO",
        "Common/MU_OEM_SAMPLE",
        "Silicon/Arm/MU_TIANO",
        "Features/DFCI",
        "Features/CONFIG",
        "Binaries",
## woa-msmnile patch start
        "Silicon/QC/"+SiliconName
## woa-msmnile patch end
    )


    # ####################################################################################### #
    #                         Configuration for Update & Setup                                #
    # ####################################################################################### #
class SettingsManager(UpdateSettingsManager, SetupSettingsManager, PrEvalSettingsManager, ParseSettingsManager):

    def GetPackagesSupported(self):
        ''' return iterable of edk2 packages supported by this build.
        These should be edk2 workspace relative paths '''
        return CommonPlatform.PackagesSupported

    def GetArchitecturesSupported(self):
        ''' return iterable of edk2 architectures supported by this build '''
        return CommonPlatform.ArchSupported

    def GetTargetsSupported(self):
        ''' return iterable of edk2 target tags supported by this build '''
        return CommonPlatform.TargetsSupported

    def GetRequiredSubmodules(self):
        """Return iterable containing RequiredSubmodule objects.

        !!! note
            If no RequiredSubmodules return an empty iterable
        """
        return [
            RequiredSubmodule("Binaries", True),
            RequiredSubmodule("Common/MU_OEM_SAMPLE", True),
            RequiredSubmodule("Common/MU_TIANO", True),
            RequiredSubmodule("Common/MU", True),
            RequiredSubmodule("Features/CONFIG", True),
            RequiredSubmodule("Features/DFCI", True),
            RequiredSubmodule("MU_BASECORE", True),
            RequiredSubmodule("Platforms/OpensslPkg/Library/OpensslLib/openssl", True),
            RequiredSubmodule("Platforms/SurfaceDuoACPI", True),
            RequiredSubmodule("Silicon/Arm/MU_TIANO", True),
        ]

    def SetArchitectures(self, list_of_requested_architectures):
        ''' Confirm the requests architecture list is valid and configure SettingsManager
        to run only the requested architectures.

        Raise Exception if a list_of_requested_architectures is not supported
        '''
        unsupported = set(list_of_requested_architectures) - \
            set(self.GetArchitecturesSupported())
        if len(unsupported) > 0:
            errorString = (
                "Unsupported Architecture Requested: " + " ".join(unsupported))
            logging.critical( errorString )
            raise Exception( errorString )
        self.ActualArchitectures = list_of_requested_architectures

    def GetWorkspaceRoot(self):
        ''' get WorkspacePath '''
        return CommonPlatform.WorkspaceRoot

    def GetActiveScopes(self):
        ''' return tuple containing scopes that should be active for this process '''
        return CommonPlatform.Scopes

    def FilterPackagesToTest(self, changedFilesList: list, potentialPackagesList: list) -> list:
        ''' Filter other cases that this package should be built
        based on changed files. This should cover things that can't
        be detected as dependencies. '''
        build_these_packages = []
        possible_packages = potentialPackagesList.copy()
        for f in changedFilesList:
            # BaseTools files that might change the build
            if "BaseTools" in f:
                if os.path.splitext(f) not in [".txt", ".md"]:
                    build_these_packages = possible_packages
                    break

            # if the azure pipeline platform template file changed
            if "platform-build-run-steps.yml" in f:
                build_these_packages = possible_packages
                break

        return build_these_packages

    def GetPlatformDscAndConfig(self) -> tuple:
        ''' If a platform desires to provide its DSC then Policy 4 will evaluate if
        any of the changes will be built in the dsc.

        The tuple should be (<workspace relative path to dsc file>, <input dictionary of dsc key value pairs>)
        '''
## woa-msmnile patch start
        return f"{PackageName}/{PlatformName}{'NoSb' if not SecureBoot else ''}.dsc", {}

    def GetName(self):
        return PackageName
## woa-msmnile patch end

    def GetPackagesPath(self):
        ''' Return a list of paths that should be mapped as edk2 PackagesPath '''
        return CommonPlatform.PackagesPath

    # ####################################################################################### #
    #                         Actual Configuration for Platform Build                         #
    # ####################################################################################### #
class PlatformBuilder(UefiBuilder, BuildSettingsManager):
    def __init__(self):
        UefiBuilder.__init__(self)

    def AddCommandLineOptions(self, parserObj):
        ''' Add command line options to the argparser '''

        # In an effort to support common server based builds this parameter is added.  It is
        # checked for correctness but is never uses as this platform only supports a single set of
        # architectures.
        parserObj.add_argument('-a', "--arch", dest="build_arch", type=str, default="AARCH64",
            help="Optional - CSV of architecture to build.  AARCH64 is used for PEI and "
            "DXE and is the only valid option for this platform.")

    def RetrieveCommandLineOptions(self, args):
        '''  Retrieve command line options from the argparser '''
        if args.build_arch.upper() != "AARCH64":
            raise Exception("Invalid Arch Specified.  Please see comments in PlatformBuild.py::PlatformBuilder::AddCommandLineOptions")

    def GetWorkspaceRoot(self):
        ''' get WorkspacePath '''
        return CommonPlatform.WorkspaceRoot

    def GetPackagesPath(self):
        ''' Return a list of paths that should be mapped as edk2 PackagesPath '''
        result = [
            shell_environment.GetBuildVars().GetValue("FEATURE_CONFIG_PATH", "")
        ]
        for a in CommonPlatform.PackagesPath:
            result.append(a)
        return result

    def GetActiveScopes(self):
        ''' return tuple containing scopes that should be active for this process '''
        return CommonPlatform.Scopes

## woa-msmnile patch start
    def GetOutputDirectory(self):
        ''' Return the output directory for this platform '''
        return self.env.GetValue("OUTPUT_DIRECTORY")

    def GetOutputBinDirectory(self):
        ''' Return the output directory with binaries '''
        toolchain_tag = self.env.GetValue("TOOL_CHAIN_TAG")
        target = self.env.GetValue("TARGET")
        out_dir = self.env.GetValue("OUTPUT_DIRECTORY")
        return os.path.join(out_dir, f"{target}_{toolchain_tag}")

    def GetDTBName(self):
        ''' Return the name of device's dtb '''
        target_device = self.env.GetValue("TARGET_DEVICE")
        linenum = target_device.find('-') + 1
        dtbname = target_device[linenum:] + '.dtb'
        return dtbname
## woa-msmnile patch end

    def GetName(self):
        ''' Get the name of the repo, platform, or product being build '''
        ''' Used for naming the log file, among others '''
## woa-msmnile patch start
        return PackageName
## woa-msmnile patch end

    def GetLoggingLevel(self, loggerType):
        """Get the logging level depending on logger type.

        Args:
            loggerType (str): type of logger being logged to

        Returns:
            (Logging.Level): The logging level

        !!! note "loggerType possible values"
            "base": lowest logging level supported

            "con": logs to screen

            "txt": logs to plain text file
        """
        return logging.INFO
        return super().GetLoggingLevel(loggerType)

    def SetPlatformEnv(self):
        logging.debug("PlatformBuilder SetPlatformEnv")
## woa-msmnile patch start
        self.env.SetValue("PRODUCT_NAME", PlatformName, "Platform Hardcoded")
        self.env.SetValue("ACTIVE_PLATFORM", PackageName+"/"+PlatformName+f"{'NoSb' if not SecureBoot else ''}.dsc", "Platform Hardcoded")
## woa-msmnile patch end
        self.env.SetValue("TARGET_ARCH", "AARCH64", "Platform Hardcoded")
        self.env.SetValue("TOOL_CHAIN_TAG", "CLANGPDB", "set default to clangpdb")
        self.env.SetValue("EMPTY_DRIVE", "FALSE", "Default to false")
        self.env.SetValue("RUN_TESTS", "FALSE", "Default to false")
        self.env.SetValue("SHUTDOWN_AFTER_RUN", "FALSE", "Default to false")
        # needed to make FV size build report happy
        self.env.SetValue("BLD_*_BUILDID_STRING", "Unknown", "Default")
        # Default turn on build reporting.
        self.env.SetValue("BUILDREPORTING", "TRUE", "Enabling build report")
        self.env.SetValue("BUILDREPORT_TYPES", "PCD DEPEX FLASH BUILD_FLAGS LIBRARY FIXED_ADDRESS HASH", "Setting build report types")
        self.env.SetValue("BLD_*_MEMORY_PROTECTION", "TRUE", "Default")
        # Include the MFCI test cert by default, override on the commandline with "BLD_*_SHIP_MODE=TRUE" if you want the retail MFCI cert
        self.env.SetValue("BLD_*_SHIP_MODE", "FALSE", "Default")
        self.env.SetValue("CONF_AUTOGEN_INCLUDE_PATH", self.edk2path.GetAbsolutePathOnThisSystemFromEdk2RelativePath("Platforms", "AndromedaPkg", "Include"), "Platform Defined")
        self.env.SetValue("MU_SCHEMA_DIR", self.edk2path.GetAbsolutePathOnThisSystemFromEdk2RelativePath("Platforms", "AndromedaPkg", "CfgData"), "Platform Defined")
        self.env.SetValue("MU_SCHEMA_FILE_NAME", "AndromedaPkgCfgData.xml", "Platform Hardcoded")
## woa-msmnile patch start
        # Ship Device Name
        self.env.SetValue("BLD_*_TARGET_DEVICE", self.env.GetValue("TARGET_DEVICE"), "Default")
        # Ship DTB Name
        self.env.SetValue("BLD_*_FDT", self.GetDTBName(), "Default")
## woa-msmnile patch end
        return 0

    def PlatformPreBuild(self):
        return 0

    def PlatformPostBuild(self):
## woa-msmnile patch start
        logging.info("Building Android Boot Image.")
        makeAndroidImage(self.GetOutputBinDirectory(), self.GetOutputDirectory(), self.GetWorkspaceRoot(), self.env.GetValue("TARGET_DEVICE"), self.GetDTBName())
## woa-msmnile patch end
        return 0

    def FlashRomImage(self):
        return 0
