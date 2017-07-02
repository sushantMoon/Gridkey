# Flipkart Gridlock Challenge - Reduce Bangalore's Traffic
[HackerEarth](https://www.hackerearth.com/sprints/flipkart-hackathon/)


# Installation 

* Virtual Env and OpenCV 
	Look into the steps mentioned inside OpenCV Folder
* Remaining python libraries for Car Detection in the same virtual env where you have installed OpenCV
	Install the libraries with correct versions mentioned in requirements.txt, use the command like `pip install -r requirements.txt`   

# Car Detections

Get Inside the python virtual environment created during installation process.
Run `juypter notebook` and open `vechile detection.ipynb`

Run this Python Notebook for simulating the results.


The following are some of our results.

![Result1](./Car%20Detection/Output/Images/002.jpeg)
![Result2](./Car%20Detection/Output/Images/004.jpeg)
![Result3](./Car%20Detection/Output/Images/005.jpeg)
![Result4](./Car%20Detection/Output/Images/jp1.jpeg)
![Result5](./Car%20Detection/Output/Images/jp2.jpeg)
![Result6](./Car%20Detection/Output/Images/jp3.jpeg)
![Result7](./Car%20Detection/Output/Images/jp4.jpeg)

![Result8](./Car%20Detection/Output/Images/CarDetection-02.jpeg)
![Result9](./Car%20Detection/Output/Images/CarDetection-01.jpeg)


## Vedio Links

* https://youtu.be/ntN3EfuHKr0
* https://youtu.be/9dJ2ICz7ghE

## Note : 

1. The weights obtained after training the model are [tiny-yolo.weights](https://drive.google.com/file/d/0B8b_yIDEINATbHFtSk1XRVMzVE0/view?usp=sharing) (181 Mb). They are to be downloaded and used.
2. For the images we would have to resize them , one can use command like `mogrify -resize 1280x720 *.jpg` to in place resize the images [Reference](https://askubuntu.com/a/25134)




# Future Works for building this prototype into Traffic Optimisation problem.

	* Training the model further for Bike, Cab and partial Image detection.
	* Developing the network graph of traffic data, eg. Like simple count of total vechiles on any signal, taking them as weights on that node(traffic signal) with roads as edges connecting to another node(traffic signal).
	* We shall be then solving network optimization problem at any given instance for calculating the most optimal timings for the signals.
	* More features like speed detection, number plate detection, helmet & seat beat detections, etc, can be further added.  