import os
from building import *

# 获取当前目录
cwd = GetCurrentDir()
CPPPATH = []
src     = []

# component
# ## ali-link-sdk\LinkSDK\LinkSDK/components\bootstrap
# src += Glob('LinkSDK/components/bootstrap/*.c')
# CPPPATH += [cwd + '/LinkSDK/components/bootstrap']
# ## ali-link-sdk\LinkSDK\LinkSDK/components\compress
# src += Glob('LinkSDK/components/compress/*.c')
# CPPPATH += [cwd + '/LinkSDK/components/compress']
# ## ali-link-sdk\LinkSDK\LinkSDK/components\data-model
# src += Glob('LinkSDK/components/data-model/*.c')
# CPPPATH += [cwd + '/LinkSDK/components/data-model']
# ## ali-link-sdk\LinkSDK\LinkSDK/components\devinfo
# src += Glob('LinkSDK/components/devinfo/*.c')
# CPPPATH += [cwd + '/LinkSDK/components/devinfo']
# ## ali-link-sdk\LinkSDK\LinkSDK/components\diag
# src += Glob('LinkSDK/components/diag/*.c')
# CPPPATH += [cwd + '/LinkSDK/components/diag']
# ## ali-link-sdk\LinkSDK\LinkSDK/components\logpost
# src += Glob('LinkSDK/components/logpost/*.c')
# CPPPATH += [cwd + '/LinkSDK/components/logpost']
# ## ali-link-sdk\LinkSDK\LinkSDK/components\mqtt_upload
# src += Glob('LinkSDK/components/mqtt_upload/*.c')
# CPPPATH += [cwd + '/LinkSDK/components/mqtt_upload']
## ali-link-sdk\LinkSDK\LinkSDK/components\ntp
# src += Glob('LinkSDK/components/ntp/*.c')
# CPPPATH += [cwd + '/LinkSDK/components/ntp']
# ## ali-link-sdk\LinkSDK\LinkSDK/components\ota
# src += Glob('LinkSDK/components/ota/*.c')
# CPPPATH += [cwd + '/LinkSDK/components/ota']
# ## ali-link-sdk\LinkSDK\LinkSDK/components\shadow
# src += Glob('LinkSDK/components/shadow/*.c')
# CPPPATH += [cwd + '/LinkSDK/components/shadow']
## ali-link-sdk\LinkSDK\LinkSDK/components\subdev
src += Glob('LinkSDK/components/subdev/*.c')
CPPPATH += [cwd + '/LinkSDK/components/subdev']
# ## ali-link-sdk\LinkSDK\LinkSDK/components\task
# src += Glob('LinkSDK/components/task/*.c')
# CPPPATH += [cwd + '/LinkSDK/components/task']

# core
## ali-link-sdk\LinkSDK\core\sysdep
src += Glob('LinkSDK/core/sysdep/*.c')
CPPPATH += [cwd + '/LinkSDK/core/sysdep']
## ali-link-sdk\LinkSDK\core\utils
src += Glob('LinkSDK/core/utils/*.c')
CPPPATH += [cwd + '/LinkSDK/core/utils']
## ali-link-sdk\LinkSDK\core
src += Glob('LinkSDK/core/*.c')
CPPPATH += [cwd + '/LinkSDK/core']

# external
src += Glob('LinkSDK/external/*.c')

# ## applications\ali-link-sdk\LinkSDK\external\libdeflate
# src += Glob('LinkSDK/external/libdeflate/lib/*.c')
# CPPPATH += [cwd + '/LinkSDK/external/libdeflate/lib']
# CPPPATH += [cwd + '/LinkSDK/external/libdeflate']

# ## applications\ali-link-sdk\LinkSDK\external\mbedtls
# src += Glob('LinkSDK/external/mbedtls/library/*.c')
# CPPPATH += [cwd + '/LinkSDK/external/mbedtls/include']

# portfiles
src += Glob('LinkSDK/portfiles/aiot_port/rtthread_port.c')

# samples
# src += Glob('samples/mqtt_basic_demo.c')
# src += Glob('samples/subdev_basic_demo.c')

group = DefineGroup('ali_link_sdk', src, depend = [''], CPPPATH = CPPPATH)

Return('group')
