# Homework 7: Linux CLI Practice

## Overview
This assignment provided practice with Linux CLI tools that will be useful in upcoming assignments.

## Deliverables

### Problem 1
`$wc -w lorem-ipsum.txt`
![Word Count](assets/HW7_image1.png)

### Problem 2
`$wc -m lorem-ipsum.txt`
![Char Count](assets/HW7_image2.png)

### Problem 3
`$wc -l lorem-ipsum.txt`
![Line Count](assets/HW7_image3.png)

### Problem 4
`$sort -h file-sizes.txt`

The output of this one had a LOT of stuff. The output ended with 72G
![Sorting](assets/HW7_image4.png)

### Problem 5
`$sort -h -r file-sizes.txt`

The output of this one also had a LOT of stuff. The output ended with 0.
![Sorting](assets/HW7_image5.png)

### Problem 6
`$cut -d ',' -f 3 log.csv`
![Cut IP](assets/HW7_image6.png)

### Problem 7
`$cut -d ',' -f 2,3 log.csv`
![Cut other stuff](assets/HW7_image7.png)

### Problem 8
`$cut -d ',' -f 1,4 log.csv`
![Cut more stuff](assets/HW7_image8.png)

### Problem 9
`$head -n 3 gibberish.txt`
![Read head](assets/HW7_image9.png)

### Problem 10
`$tail -n 2 gibberish.txt`
![Read tail](assets/HW7_image10.png)

### Problem 11
`$tail -n +2 log.csv`
![Read without header](assets/HW7_image11.png)

### Problem 12
`$grep -w and gibberish.txt`
![Find "and"](assets/HW7_image12.png)

### Problem 13
`$grep -w we -n gibberish.txt`
![Find "we"](assets/HW7_image13.png)

### Problem 14
`$grep -o -P 'to [a-z]+' -i gibberish.txt`
![Find "to <word>"](assets/HW7_image14.png)

### Problem 15
`$grep -c fpgas -i fpgas.txt`
![Find FPGAs](assets/HW7_image15.png)

### Problem 16
`$grep -P '\b\w*(ot|er|ile)\b' fpgas.txt`
![Find rhymes](assets/HW7_image16.png)

### Problem 17
`$grep -c "^\s--" -r ../../hdl/*/*.vhd`
![Find comments](assets/HW7_image17.png)

### Problem 18
`$ls > ls-output.txt`
![Redirect output](assets/HW7_image18.png)

### Problem 19
`$sudo dmesg | grep "CPU topo"`
![Piping](assets/HW7_image19.png)

### Problem 20
`$find ../../hdl/* -iname '*.hdl' | wc -w`
![Count hdl files](assets/HW7_image20.png)

### Problem 21
`$grep -r "[--]" ../../hdl/*/*.vhd | wc -l`
![Return comment lines](assets/HW7_image21_1.png)

### Problem 22
`$grep -n FPGAs -i fpgas.txt | cut -d ':' -f 1`
![Print line numbers with word](assets/HW7_image21.png)

### Problem 23
`$du -h * | sort -h | tail -n 3`
![Find 3 largest directories](assets/HW7_image23.png)
