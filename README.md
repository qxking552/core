Installation
===
```
sudo apt-get update
sudo apt-get install cmake gcc make libleveldb1v5 libpcsclite1 libpcsclite-dev libleveldb-dev libboost-all-dev gcc g++ ntp
```


Use ntp
===
```
sudo service ntp stop
sudo apt-get install ntpdate  
sudo ntpdate pool.ntp.org
sudo service ntp start
```

Install OpenSSL 1.1
===
```
cd /usr/local/src
sudo wget https://www.openssl.org/source/openssl-1.1.0g.tar.gz && sudo tar xzvf openssl-1.1.0g.tar.gz && cd openssl-1.1.0g
sudo ./config -Wl,--enable-new-dtags,-rpath,'$(LIBRPATH)'
sudo make
sudo make install

openssl version # make sure it is version 1.1
```

Install UBIC
===
```
cd /usr/local/src
git clone 
cd core-master
chmod 777 Static/install.sh
cmake CMakeLists.txt
make
sudo make install
```

Run the server
===
```
/etc/init.d/ubic start
```

Stop the server
===
```
/etc/init.d/ubic stop
```

Open the web interface
===
To open the web interface you have to open 127.0.0.1:6789/#<apiKey> in your browser.

You will find your api key in the ```~/ubic/config.ini``` file.

/!\ Warning: For security reasons the web interface can not be opened remotly by typing <your server ip>:6789/#<apiKey>.
If you want to open the web insterface of your sever do a port forwarding over SSH, and forward the ports 6789 and 12303 to the ports 6789 and 12303 on your local machine.
