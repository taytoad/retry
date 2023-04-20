# retry
A simple command repeater

*This was only tested on linux but probably works on other systems*

### Usage

retry "[Command]" -options

#### Example:

retry checkUpdate -r 2 -t 200

#### Parameters
* -r|-R: number of retries if it fails
* -t|-T: time between the command to run it again\n
* -h|-H: help menu

