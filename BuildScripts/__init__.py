import importlib
import logging
import os
import sys


def sys_exit(code):
    del logging.root
    logging.root = logging.RootLogger(logging.WARNING)
    print(code)
sys.exit = sys_exit
from argparse import Namespace
banner = r"""Invoking Stuart
     ) _     _
    ( (^)-~-(^)
__,-.\_( 0 0 )__,-.___
  'W'   \   /   'W'
         >o<"""
print(banner)
def prepare_build(buildtype, package_name, setup:bool=False, update:bool=False):
    module = importlib.import_module(f'BuildScripts.{package_name}.PlatformBuild')

    from edk2toolext.invocables.edk2_setup import Edk2PlatformSetup
    from edk2toolext.invocables.edk2_update import Edk2Update
    SCRIPT_PATH = os.path.relpath(module.__file__)

    args, remaining = Namespace(setup=setup, update=update), ['-t', buildtype]
    new_args = ["stuart", "-c", SCRIPT_PATH]
    new_args = new_args + remaining
    sys.argv = new_args
    if args.setup:
        print(f"Running stuart_setup -c {SCRIPT_PATH}")
        Edk2PlatformSetup().Invoke()
    elif args.update:
        print(f"Running stuart_update -c {SCRIPT_PATH}")
        Edk2Update().Invoke()
    else:
        print("!Nothing Provided!")

def build(target, target_device, package_name, sb:bool=False):
    from edk2toolext.invocables.edk2_platform_build import Edk2PlatformBuild
    module = importlib.import_module(f'BuildScripts.{package_name}.PlatformBuild')
    module.SecureBoot = sb
    print(f'SecureBoot: {module.SecureBoot}')
    SCRIPT_PATH = os.path.relpath(module.__file__)
    new_args = ["stuart", "-c", SCRIPT_PATH]
    new_args = new_args + [f'TARGET={target}', f'TARGET_DEVICE={target_device}']
    sys.argv = new_args
    print(f"Running stuart_build -c {SCRIPT_PATH}")
    Edk2PlatformBuild().Invoke()