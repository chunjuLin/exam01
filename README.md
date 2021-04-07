# exam01

switch

We have three different switches, one for increase slew, another one for decrease slew 
and the last one for selected the slew. I set a variable for the current type of slew. 
When the first button is pushed, which means we get the HIGH signal. We let the variable add by 1.
When the second button is pushed, we decrease the variable by 1. To implement the select function 
we set another variable called done, which is initial as 0. If the selection button is pushed. 
We will set the done = 1.This done variable will disable the up and down function.

LCD

We have to use the lcd to show the current slew. If the type is one, it will show 1/8, else if it is two
it will show 1/4, else if it is 3, it will show 1/2. last, if it is 4, it will show 1.

Generate waveform

I use the DAC to implement this part. I cut one wave into 240 parts.I seperate a wave into three part, the climb up 
part. The high part, and the drop down part. Because the freuqency don't have to change i fix the interval.


Measure

If the frequency is larger than that, the amplitude of the wave will drop significanly.
 I use the picoscope to connect the out put frequency and get the correct frequency.

Sample

Here is a problem, we are generating the wave while sampling. How can I done such thing together without 
affecting the original frequency? So I first generate the for some time without sample anything. After generating
for some period, we start to sample while we are generating the wave. Because we want to sample as accurate as
 possible so I put sample inside the wave generating loop so it will have equal to the generating rate. We only take 
1000 points and store it in the array. After obtaining the wave, we print it out on the screen.

Analysis

Last, we have to use the python to get the FFT. Basically, the FFT is similar to the original one. However our sampling
rate is 100, so we have to make the Fs = 1000. And calculate out the related range of the graph. I make the graph print
out 1 second in the graph.And I cut the x and y axis in frequency domain.

