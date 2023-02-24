# so_long
This is a 2D game.

## Requirements
* warning The project must be written in accordance with the Norm

### The Norm is a programming standard that defines a set of rules to follow when writing code at 42. It applies to all C projects within the Common Core       by default, and to any project where it's specified. These are some of them:
    Each function must be maximum 25 lines, not counting the function's own curly brackets.

    Each line must be at most 80 columns wide, comments included.

    A function can take 4 named parameters maximum.

    You can't declare more than 5 variables per function.

    You're not allowed to use: for , do...while , switch , case ,  goto  ,
    ternary operators such as `?' and VLAs - Variable Length Arrays.
    The norminette (as we call the norm at 42) is in python and open source.

    Its repository is available at https://github.com/42School/norminette.

## How does it work?

in Linux:

To play, first compile the project with make:

$ make
In case you wanna play the bonus version:

$ make bonus
So, run ./so_long followed by the map:

$ ./so_long assets/map/map1.ber	
or
$ ./so_long assets/map/map2.ber
For bonus:

# ./so_long_bonus assets/map/map6.ber
or
./so_long_bonus assets/map/map7.ber
