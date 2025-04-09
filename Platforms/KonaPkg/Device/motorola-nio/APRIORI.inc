APRIORI DXE {
        INF MdeModulePkg/Core/Dxe/DxeMain.inf
        INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/EnvDxe/EnvDxe.inf
        INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
        INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
        #    INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/MdeModulePkg/Universal/TimestampDxe/TimestampDxe.inf
        INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
        INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
        INF ArmPkg/Drivers/ArmGic/ArmGicDxe.inf
        INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
        INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf
        INF AndromedaPkg/Driver/RamPartitionDxe/RamPartitionDxe.inf
#        INF ArmPkg/Drivers/ArmPsciMpServicesDxe/ArmPsciMpServicesDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/MbmPkg/Core/Drivers/MotBootFlagsDxe/MotBootFlagsDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/SmemDxe/SmemDxe.inf
#        INF QcomPkg/Drivers/DynamicRamDxe/DynamicRamDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/DALSYSDxe/DALSYSDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/HWIODxe/HWIODxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/ChipInfoDxe/ChipInfoDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/PlatformInfoDxe/PlatformInfoDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/HALIOMMUDxe/HALIOMMUDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/ULogDxe/ULogDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/CmdDbDxe/CmdDbDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/PwrUtilsDxe/PwrUtilsDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/NpaDxe/NpaDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/RpmhDxe/RpmhDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/PdcDxe/PdcDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/VcsDxe/VcsDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/ClockDxe/ClockDxe.inf
#        INF QcomPkg/Drivers/ClockSpeedUpDxe/ClockSpeedUpDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/SPMIDxe/SPMIDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/ShmBridgeDxe/ShmBridgeDxeLA.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/TzDxe/ScmDxeLA.inf
        #    INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/DALTLMM.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/ResetRuntimeDxe/ResetRuntimeDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/PmicDxe/PmicDxeLa.inf
        FILE DRIVER = 6b38f7b4-ad98-40e9-9093-aca2b5a253c4 {
                SECTION PE32 = $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.efi
                SECTION UI = "DiskIoDxe"
        }

        FILE DRIVER = 1fa1f39e-feff-4aae-bd7b-38a070a3b609 {
                SECTION PE32 = $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.efi
                SECTION UI = "PartitionDxe"
        }
        INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf
        #    INF MdeModulePkg/Universal/FvSimpleFileSystemDxe/FvSimpleFileSystemDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/SdccDxe/SdccDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/PatchedBinaries/UFSDxe.inf
        INF FatPkg/EnhancedFatDxe/Fat.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/TzDxe/TzDxeLA.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/VariableDxe/VariableDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/QcomWDogDxe/QcomWDogDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/DDRInfoDxe/DDRInfoDxe.inf
#        INF AndromedaPkg/Driver/SimpleFbDxe/SimpleFbDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/MbmPkg/Core/Drivers/MotStorageDxe/MotStorageDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/MbmPkg/Core/Drivers/MotUtagsDxe/MotUtagsDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/MbmPkg/Core/Drivers/MotUtagsDictDxe/MotUtagsDictDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/MbmPkg/Core/Drivers/MotHwIdDxe/MotHwIdDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/MbmPkg/Core/Drivers/MotCoreServicesDxe/MotCoreServicesDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/MbmPkg/Core/Drivers/AbDxe/AbDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/DisplayDxe/DisplayDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/PILProxyDxe/PILProxyDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/PILDxe/PILDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/SPSSDxe/SPSSDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/CPRDxe/CPRDxe.inf
        INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/ASN1X509Dxe/ASN1X509Dxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/SecRSADxe/SecRSADxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/VerifiedBootDxe/VerifiedBootDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
        INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
        INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
        INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
        INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
        INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/FontDxe/FontDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/QcomBds/QcomBds.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/SPIDxe/SPIDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/I2CDxe/I2CDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/AdcDxe/AdcDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/QcomChargerDxe/QcomChargerDxeLA.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/ChargerExDxe/ChargerExDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
        FILE DRIVER = B7F50E91-A759-412C-ADE4-DCD03E7F7C28 {
                SECTION PE32 = $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/XhciDxe/XhciDxe.efi
                SECTION UI = "XhciDxe"
        }

        FILE DRIVER = 240612B7-A063-11D4-9A3A-0090273FC14D {
                SECTION PE32 = $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/UsbBusDxe/UsbBusDxe.efi
                SECTION UI = "UsbBusDxe"
        }

        FILE DRIVER = 2D2E62CF-9ECF-43B7-8219-94E7FC713DFE {
                SECTION PE32 = $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/UsbKbDxe/UsbKbDxe.efi
                SECTION UI = "UsbKbDxe"
        }

        FILE DRIVER = 9FB4B4A7-42C0-4BCD-8540-9BCC6711F83E {
                SECTION PE32 = $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/UsbMassStorageDxe/UsbMassStorageDxe.efi
                SECTION UI = "UsbMassStorageDxe"
        }
#        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/PatchedBinaries/UsbConfigDxe.inf
#        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/ButtonsDxe/ButtonsDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/TsensDxe/TsensDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/LimitsDxe/LimitsDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/GpiDxe/GpiDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/HashDxe/HashDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/CipherDxe/CipherDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/MacDxe/MacDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/RNGDxe/RngDxe.inf
        INF $(PACKAGE_NAME)/Device/$(TARGET_DEVICE)/Binaries/QcomPkg/Drivers/SimpleTextInOutSerialDxe/SimpleTextInOutSerial.inf
        INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
        INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
        INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf
        #    INF MbmPkg/Core/Drivers/MbmModeDxe/MbmModeDxe.inf
        #    INF MbmPkg/Core/Drivers/MotSolDxe/MotSolDxe.inf
        #    INF MbmPkg/Core/Drivers/BacklightDxe/BacklightDxe.inf
}
