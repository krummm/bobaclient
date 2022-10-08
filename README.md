# bobaclient

Dependencies: zip and curl

A simple and lightweight client for bobashare.\
All credits to bobashare at https://bbaovanc.com/

All commands will be ran with the structure of 'bobaclient [flag] [flag] [flag] filename.xyz\
The first flag here is always required, and the second flag is optional for things such as randomized filename.\
The maximum amount of flags possible is three.\

Valid flags:

'bobaclient h' to display help message.\
'bobaclient u' to upload the specified file to bobashare and return the URL.
'bobaclient u r' to upload the specified file with a randomized name to bobashare and return the URL.\
'bobaclient u z' in the parent directory of the folder you would like to upload all files to bobashare as a .zip and return the URL.
'bobaclient u z r' does the same as 'bobaclient u z', with a randomized filename.\

Example command: bobaclient u filename.xyz\
Example command: bobaclient u r filename.xyz
