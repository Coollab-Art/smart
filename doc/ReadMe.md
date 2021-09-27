## `keep_above` and `keep_below`

Even though they are just aliases for `min` and `max`, they are very important because they give clearer names. I personaly always have to think for 30 seconds to know if I should use a min or a max to perform the operation I want (and every other time I get it wrong).

Also it states the intent better : I don't just want to compare two numbers, I have an input `x` and I apply a function to it `keep_above_0: x -> keep_above(0, x)`

![Graph of x -> clamp_bot(x, 0)](./keep_above.png)