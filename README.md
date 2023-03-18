# A project from the second ring of the core - so_long

*So Long is a 2D game in the course of the core curriculum at 42 Wolfsburg.
You need to collect hearts while finding your love.
Be careful! As soon as your heart breaks, the game is over.
Don't allow that anyone breaks your heart, and find your better half!*

*There is a bonus version in which So Long turns into a multiplayer game with animations. Fight all odds together with your loved one!*

> ## “The sun doesn't always shine in life, but we can share the umbrella and survive the storm together.”

<a name="0"></a>
# [Table of content](#0)
- [Remark](#1.1)
- [Introduction to your role as a player](#1)
- [Play and fight all odds](#2)
- [Requirements for the maps](#3)
- [Your benefits of So Long](#4)
- [Installation](#5)
- [Implementation](#6)
- [Examples](#7)
- [Deinstallation](#8)

<a name="1.1"></a>
# [Remark](#1.1)
I used the school's graphical library: the MiniLibX! This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events. Due to legal regulations, the MiniLibX is not included in the current directory! Please keep in mind that you need to have access to the MiniLibx developed by 42 to play So Long. The bonus of the repository is not completely normed and may vary from the subject's instructions on intra.  

<a name="1"></a>
# [Introduction to your role as a player](#1)
Note that I included [MiniLibX](https://github.com/42Paris/minilibx-linux) as a graphics library, and I used my own [libft](https://github.com/lspohle/42_so_long/blob/main/libft) for [printf](https://github.com/lspohle/42_so_long/blob/main/libft/ft_printf.c), [memset](https://github.com/lspohle/42_so_long/blob/main/libft/ft_memset.c) and [strncmp](https://github.com/lspohle/42_so_long/blob/main/libft/ft_strncmp.c). The libft also contains the function [get_next_line](https://github.com/lspohle/42_so_long/blob/main/libft/get_next_line_bonus.c) to read from a file descriptor. 

|Character|Description|Image|Significance|
|:--:|:--------:|:----:|:----:|
|0|Empty Space|empty.xpm|**You may step on the very ground of the map.**|
|1|Wall|wall.xpm|**You cannot move through the walls of the map.**|
|C|Collectible|heart1.xpm/heart2.xpm|**You need to collect the displayed hearts. If you have collected all of them you can come together with your love.**|
|P|Player|woman.xpm/man.xpm|**You are the player. Depending on the map you choose you will start at different positions.**|
|E|Loved one|woman.xpm/man.xpm|**You want to come together with your loved one. But you will only become a couple if you have collected all the displayed hearts. You have the chance to fight all odds together!**|
|R|Rival|broken_heart1.xpm/broken_heart2.xpm|**You need to take care of yourself. Do not step onto those spaces! As soon as you do your heart will break and the game is over. The same applies for your loved one.**|

<a name="2"></a>
# [Play and fight all odds](#2)
### In the following the key codes for you as **the player** are defined:
|Key code|Description|Function|
|:--:|:--------:|:--------:|
|123|Left arrow|**Moves left**|
|124|Right arrow|**Moves right**|
|125|Down arrow|**Moves down**|
|126|Up arrow|**Moves up**|
|53|Escape|**Closes the window and terminates the game**|

### In the following the key codes for you as **the loved one** are defined:
|Key code|Description|Function|
|:--:|:--------:|:--------:|
|0|A|**Moves left**|
|2|D|**Moves right**|
|1|S|**Moves down**|
|13|W|**Moves up**|
|53|Escape|**Closes the window and terminates the game**|

<a name="3"></a>
# [Requirements for the map](#3)
- [x] It must be **rectangular**.
- [x] It must be **rectangular**.
- [x] It must be **surrounded by walls**.
- [x] It must contain exactly **one exit**.
- [x] It must contain exactly **one starting position**.
- [x] It must contain **a valid path**.
- [x] It must contain **at least one collectible**.

<a name="4"></a>
# [Your benefits of So Long](#4)
  
-  **Installed and implemented easily**

     - [x] You can easily implement *So Long* as explained in [Installation](#3) and [Implementation](#4).
-  **Customize the existing maps**

     - [x] You can easily customize the existing maps. The program will check whether your map is valid and meets the [requirements](#5).
-  **Create your own map easily**

      - [x] You can easily modify the content of the directory [maps](https://github.com/lspohle/PRIVATE_a_little_valentine/tree/main/maps) and create your own map.
-  **Create your own images easily**

      - [x] You can easily modify the images of the directory [images](https://github.com/lspohle/PRIVATE_a_little_valentine/tree/main/images) and create your own storyline.
-  **Adjust the colors or the content of the output in the shell**

      - [x] You may easily adjust the colors of the output in the shell/in the window by modifying the constants of the colors in [so_long.h](https://github.com/lspohle/42_so_long/blob/main/srcs/so_long.h) or [bonus_so_long.h](https://github.com/lspohle/42_so_long/blob/main/srcs/bonus_so_long.h). If you want to adjust the content of the output, immerse yourself in [display_output.c](https://github.com/lspohle/42_so_long/blob/main/srcs/display_output.c) or [bonus_display_output.c](https://github.com/lspohle/42_so_long/blob/main/srcs/bonus_display_output.c).
-  **Works on all devices with macOS**

      - [x] *So Long* works on the operating system macOS. You do not need to install anything. All necessary installations are either pre-installed on macOS or included in the repository of *So Long*. Please keep in mind that you do need to download the MiniLibX from the project page on intra.

<a name="5"></a>
# [Installation](#5)
- Install *So Long* by cloning the current repository. If you do not have an SSH key yet, you need to use the command using https. Otherwise, it is up to you to use either SSH or https.
     - SSH
      
      git clone git@github.com:lspohle/42_so_long.git
          
     - HTTPS
      
      git clone https://github.com/lspohle/42_so_long.git
      
- Download the graphical library MiniLibX on intra from [the project page of So Long](https://projects.intra.42.fr/so_long/mine). Select a version of the MiniLibX that works for the operating system you're currently using. Add the downloaded MiniLibX to the repository `42_so_long`you cloned before. Please make sure that the directory in which the content of the MiniLibX is stored is called `minilibx`.
      
      minilibx
- Go into the directory `srcs`and run the command `make`to compile.
     
      make
- Play So Long by executing the program.
    
      ./so_long ../maps/[the_map_of_your_choice] [the_player_of_your_choice] [the_loved_one_of_your_choice]
      
<a name="6"></a>
# [Implementation](#6)
- Ready to challenge youself? Find your love! 
Select a map of your choice. Take a look at the them in [maps](https://github.com/lspohle/42_so_long/tree/main/maps). Choose the character you identify most with - either woman, man or other. Last but not least: Choose a character that shall represent your loved one.

       ./so_long ../maps/[the_map_of_your_choice] [the_player_of_your_choice] [the_loved_one_of_your_choice]

<a name="7"></a>
# [Examples](#7)

https://user-images.githubusercontent.com/121381385/222758862-d51462eb-f52b-41c3-b117-ff9856bee753.mov

https://user-images.githubusercontent.com/121381385/222758107-31ea796a-9955-430b-9f99-fc7f9fb6a129.mov
