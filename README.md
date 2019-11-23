# ESP8266 RTOS test project

Just messing around with an ESP8266. This is the [ESP8266_RTOS_SDK](https://github.com/espressif/ESP8266_RTOS_SDK) `examples/get-started/hello_world` project template adapted to blink the built-in LED.

## Setup

Check out the [ESP8266_RTOS_SDK](https://github.com/espressif/ESP8266_RTOS_SDK) somewhere:
```
mkdir -p ~/code/projects
cd ~/code/projects
git clone https://github.com/espressif/ESP8266_RTOS_SDK
```

The make check seems broken in my environment and I'm installing everything in a virtualenv, if that's the case for you as well you can edit this file:
```
vim tools/check_python_dependencies.py
```

and then put `sys.exit(0)` on the line under `args = parser.parse_args()` or something.

Get the esp-open-sdk from somewhere (xtensa-lx106-elf):
```
wget https://dl.espressif.com/dl/xtensa-lx106-elf-linux64-1.22.0-100-ge567ec7-5.2.0.tar.gz
# Or check for a newer link in https://github.com/espressif/ESP8266_RTOS_SDK/blob/master/README.md
```

Or compile it yourself
```
cd ~/code/projects
git clone --recursive https://github.com/pfalcon/esp-open-sdk.git
# Or this one which is supposedly a bit more up to date https://github.com/xxxajk/esp-open-sdk
cd esp-open-sdk
make
```
And then remember the `bin/` path to put in the PATH for the next step.

Create a python 2 virtualenv (it seems to have some problems with Python 3.8 on Archlinux at least):
```
export WORKON_HOME=`pwd`
export PROJECT_HOME=`pwd`
mkvirtualenv -p python2 venv
cd $PROJECT_HOME
echo 'export IDF_PATH=$HOME/code/projects/ESP8266_RTOS_SDK; export PATH="$HOME/code/projects/xtensa-lx106-elf/bin/:$PATH"' >> $WORKON_HOME/venv/postactivate
. venv/bin/postactivate
pip install -r $HOME/code/projects/ESP8266_RTOS_SDK/tools/esp_prov/requirements.txt
pip install pyserial esptool pyparsing
```

And the next time to enter the venv do:
```
. venv/bin/activate
```

## Build the project

To compile the project run:
```
# Clean up all the things:
# make clean
make
```

## Flash

To flash the esp8266, connect it with USB, verify you have `ttyUSB0`, and then:
```
sudo -E make flash
```

And then to see the output of your program:
```
sudo -E make monitor
```

You can exit using `Ctrl + ]`. For other options see [here](https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html#monitor)
