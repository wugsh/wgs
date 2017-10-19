sudo rmmod dev_fifo 
sudo insmod dev_fifo.ko 
sudo chmod 666 /dev/dev_fifo0
sudo dmesg -c 

