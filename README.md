#Audio Rate Animation

An example on how to drive accurate, synchronized animations using the dsp cycle

Triggering events using the sample rate of audio: in Pure Data it is common to read arrays, drive events using sound objects (such as [phasor~], [sine~], [expr~] etc). This is really useful when building synchronized animations and/or different looping events. This small repo is an implementation of this idea in OpenFrameworks. The oscillator class has been forked from the AVSys workshop repository ( https://github.com/ofZach/avsys2012 )
(Built with OF 8.4 / xCode 6.1.1)

The Pd-Example folder illustrates the concept of using a saw tooth sound signal and read values from a sound buffer with its values.


(c) stc@binaura.net 2014

GPL v3