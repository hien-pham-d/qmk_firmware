- Must read:
- Configuring QMK: [https://github.com/qmk/qmk_firmware/blob/master/docs/config_options.md](https://github.com/qmk/qmk_firmware/blob/master/docs/config_options.md)
- Anatomy of keymap.c: [https://docs.qmk.fm/#/keymap?id=anatomy-of-a-keymapc](https://docs.qmk.fm/#/keymap?id=anatomy-of-a-keymapc)
- [https://docs.qmk.fm/#/syllabus](https://docs.qmk.fm/#/syllabus)
- # Build your own firmware
  
  [https://docs.qmk.fm/#/newbs](https://docs.qmk.fm/#/newbs)
- ### **Setting Up Your QMK Environment**
  
  [https://github.com/qmk/qmk_firmware/blob/master/docs/newbs_getting_started.md](https://github.com/qmk/qmk_firmware/blob/master/docs/newbs_getting_started.md)
- Install qmk:
  
  ```
  sudo apt install -y git python3-pip
  python3 -m pip install --user qmk
  
  # with Debian 12
  pipx install qmk
  
  # macos
  brew install qmk/qmk/qmk
  ```
  
  Note:
- At this step, I run QMK setup by forking and cloning the qmk_firmware github repo (follow [this instruction](https://docs.qmk.fm/#/newbs_getting_started?id=set-up-qmk))
- Setup QMK based on the cloned repo (must-run command, it will install dependent modules):
  
  ```
  qmk setup -H ~/workspace/repos/qmk_firmware
  ```
- Config qmk_home:
  
  ```
  qmk config user.qmk_home=~/workspace/repos/qmk_firmware
  ```
- ### **Building Your First Firmware**
  
  [**Configure Your Build Environment Defaults (Optional)**](https://docs.qmk.fm/#/newbs_building_firmware?id=configure-your-build-environment-defaults-optional)
  
  ```
  qmk config user.keyboard=crkbd/rev1
  qmk config user.keymap=hien-pd-dac
  ```
  
  [**Create a New Keymap**](https://docs.qmk.fm/#/newbs_building_firmware?id=create-a-new-keymap)
  
  `qmk new-keymap`  // new keymap folder with the name `hien-pd-dac` is created with the path
  
  ```
  // `keyboards/crkbd/keymaps/hien-pd-dac`
  
                            // contains config.h, keymap.c, rules.mk
  ```
  
  Note:
- Using qmk configurator to quickly gen keymap.json, then use `qmk json2c -o keymap.c keymap.json`, then manually add additional code (from default keymap.c) to `keymap.c` file.
- c2json
	- qmk c2json -km hien-pd-dac -kb crkbd/rev1  -o keymap.json keyboards/crkbd/keymaps/hien-pd-dac/keymap.c
- qmk logo generator: [https://joric.github.io/qle/](https://joric.github.io/qle/)
	- Open `Raw` tab → upload image (I have designed it using google slide) → using this raw code to use on keymap.c.
- To prevent git prompt slow down your terminal (because the size of qmk_firmware repo), use the command below to ignore status check from oh-my-zsh:
  
  ```
  git config --add oh-my-zsh.hide-status 1
  git config --add oh-my-zsh.hide-dirty 1
  ```
  
  After modify keymap.c, config.h, [rules.mk](http://rules.mk) → complie firmware by run: `qmk compile`
  
  → hex file will be build and save to qmk_firmware/.build/ dir.
- ### Flash your firmware
  
  Using QMK Toolbox or the command line `qmk flash`
  
  Note:
- On linux, if you can not flash your firmware, see the FAQ below:
  
  [https://docs.qmk.fm/#/faq_build?id=linux-udev-rules](https://docs.qmk.fm/#/faq_build?id=linux-udev-rules)
  
  ```
  sudo cp /path/to-qmk_firmware/util/udev/50-qmk.rules /etc/udev/rules.d/
  sudo udevadm control --reload-rules
  sudo udevadm trigger
  ```
- # RGB Lighting
  
  [https://docs.qmk.fm/#/feature_rgblight?id=rgb-lighting](https://docs.qmk.fm/#/feature_rgblight?id=rgb-lighting)
