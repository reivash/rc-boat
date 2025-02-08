# Radio Control Boat

I made this project to touch on electronics and radio control (RC). I always loved RCs and I decided to learn a bit with Youtube and ChatGPT while buying cheap components in Temu. 

## Technology used
- Taranis X9D Plus 2019 Radio Station. Configurable radio controller. You can even play simulations in your computer like [Liftoff]([url](https://store.steampowered.com/app/410340/Liftoff_FPV_Drone_Racing/)) and [PicaSim]([url](https://www.rowlhouse.co.uk/PicaSim/download.html)
  ).
- GR8 radio control receiver: It uses the radio protocol ACCESS which is the one Taranis X9D understands and can connect to.
- LiPo battery 11.1V 1000 mAh: The first modest size battery I found. Less than that would not power the circuit and I didn't feel safe with a big LiPo battery since they can explode.
- Arduino UNO.
- XL6019 downstepper which helps me transform the battery 11.1V into 5V for powering Arduino UNO and the GR8.
- H Bridge L298N that allows to control a higher current with a the PWM signal obtained from the GR8.
- Breadboard, AWG 22 cables for more than 5V current, leds, resistances for visual debuggability.
- General construction materials like cardboard, tape, hotglue, tin soldering, foam boards.
- 20T RC-540 motor which works on 11V.
- Plastic propeller and metal shafts to connect the motor to the propeller.

## Screenshots
![Initial LED debugging of PWM signal](https://github.com/user-attachments/assets/63078666-0e87-4369-9ec4-fcde386b3137)
![End-to-end circuit connected with H-Bridge and Motor](https://github.com/user-attachments/assets/02db7246-5d1b-4dd6-af83-71afd9cb8772)

https://github.com/user-attachments/assets/0f4d0473-ed49-4f69-8edc-58517e21a7ed

![Integration with cardboard](https://github.com/user-attachments/assets/5cefbb61-a889-41ac-a179-e1be578c43f5)

https://github.com/user-attachments/assets/8342b839-c5b5-4bd5-b915-fcefb323280b

![PXL_20250208_104158028](https://github.com/user-attachments/assets/c34349ed-802f-4275-b576-e5696bf6fb4c)
