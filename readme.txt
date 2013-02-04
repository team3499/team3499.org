How to get website to work correctly:
1. Currently, you must use either XAMPP or LAMPP, NOT APACHE (This may change in the future)

Windows: 
2. Open the XAMPP control panel
3. Click config
4. Click "httpd.conf"
5. Look for DocumentRoot and change it to "DriveLetter:\yourGit\root", the key is \root part.
6. Scroll a few lines down and do the same thing (it will say "This should be changed to whatever you set DocumentRoot to." above what you need to change.
7. Save > Exit
8. Reapeat 3 -> Click "php.ini"
9. Look for Windows: "\path1;\path2"
10. Change include_path = ".;C:\xampp\php\PEAR" to include_path = ".;C:\xampp\php\PEAR;DriveLetter:\yourGit\phpfiles", the key is the \phpfiles part.
11. Save > Exit > Start Apache

Linux:
2. 