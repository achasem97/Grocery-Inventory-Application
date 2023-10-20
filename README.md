"# Grocery-Inventory-Application" 

This project was designed to intake a txt file with a single item on each line, tally those items, and save the total of each tally to a set. Once that set was made, the set would then be output in the format requested by the user through input.

I feel like I handled the pointers very well in this project. This was a new concept to me, and I think I utilized them well in the set implementation while deleting the reference when needed.

In a weird way, the most difficult hurdle that I faced in this project was the exception throwing and catching. At one point I had changed all of the inputs to strings rather than ints for the sole purpose of not needing to throw an exception. I compared the string input to a vector of acceptable inputs, and if the input was present, the loop executed. This was not ideal and would require manual additions to the vector for every new input. The fix to my issue was just adding the a filler string variable to "clear" out the cin. Google was a major ally on this.

I think one of the most applicable tools I have gained from this c++ course is the syntax of vectors and pointers. The increase in processing speed from pointers seems to be the languages main appeal, and I would like to develop my comfort using them.

I made this program readable by adding comments to explain some of the more tricky loops. I hope that it is maintainable through these comments and understandable variable names. Also, changing the input to be ints instead of strings allows for simpler maintentenance.
