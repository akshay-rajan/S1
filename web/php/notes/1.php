<!DOCTYPE html>
<html>
    <head>
        <title>php</title>
    </head>
    <body>
        <h1><a href="https://www.w3schools.com/php/">php</a></h1>
    <div>
        <?php 
        // Variables are always attached with a '$' before them
        $php = "PHP: Hypertext Preprocessor.";

        // The '.' is used to concatenate two objects
        echo $php."<br>";

        echo "<ul><li>PHP is a widely used open source scripting language.</li></ul>";

        /* 'global' is used to access a global variable locally */
        $g = "Global variable";
        function test() {
            global $g;
            echo "Using ".$g. " Locally";
        }

        //  It is also possible to use ',' to include multiple parameters in an echo statement
        echo "Hello, ", "World ";

        // We can also use print instead of echo
        print $php;
        ?>
        <div>
            <ul>
                <li>PHP statements are not case sensitive, but variable names are!</li>
                <li>PHP is loosely typed: we don't have to specify the datatype</li>
                <li>Global variables can only be used globally (outside any function) and local variables 
                    locally (inside a particular function)</li>
                <?php 
                test();
                ?>
                <li>PHP stores all the local variables in an array named $GLOBALS[], which can be used to access 
                    global variables within a function.-- $GLOBALS['x']</li>
                <li>String is any input inside quotes.</li>
                <li>php var_dump($x) returns the datatype and value of a variable</li>
                <?php
                $a = 5;
                var_dump($a);
                ?>
                <li>Arrays in php are defined as $a = array(1, 2, 3);</li>
                <?php 
                $colors = array('orange', 'black', 'red');
                var_dump($colors);
                ?>
                <li>Variables can be emptied by setting their value to null</li>
                <li>Constants are always global</li>
                <br>
                <br>
                <div>
                    <h3>Class and Object</h3>
                    A class is a template for objects and object is an instance of a class. When individual
                    objects are created, they inherit all the properties and behaviors from the class. If
                    you create a __construct function, it will automatically be called when a new object is 
                    created. The functions inside a class are known as methods. Some variables are defined as 'public', 
                    meaning they can be accessed outside the class.<br>
                    <?php 
                    class Student {

                        // Properties
                        public $name;
                        public $roll;

                        // Methods
                        public function __construct($name, $roll) {
                            $this->name = $name;
                            $this->roll = $roll;
                        }
                        public function info() {
                            return "The student is ".$this->name." Roll No. ".$this->roll;
                        }
                    }

                    $newstudent = new Student('foo', '5');
                    echo $newstudent->info();
                    ?>
                </div>
                <div>
                    <h3><a href="https://www.w3schools.com/php/php_ref_string.asp">String Functions</a></h3>
                    <ul>
                        <li>strlen()</li>
                        <li>str_word_count()</li>
                        <li>strrev()</li> <!-- reverse a string -->
                        <li>strpos(string, word)</li> <!-- returns the starting pos of a word -->
                        <li>str_replace(wordToReplace, wordToBeReplacedWith, string)</li>
                    </ul>
                </div>
                <div>
                    <h3>Numbers</h3>
                    <ul>
                        <li>is_int($n) -- returns true if n is an integer</li>
                        <li>is_float($n) -- returns true if n is a float</li>
                    </ul>
                    <h3>Infinite</h3>
                    A value larger than PHP_FLOAT_MAX is considered infinite.
                    <ul>
                        <li>is_finite()</li>
                        <li>is_infinite()</li>
                    </ul>
                    NAN -- Not A Number -- For impossible mathematical calculations.<br>
                    is_numeric() checks if a variable is a number or a numeric string.
                </div>
                <div>
                    <h3>TypeCasting</h3>
                    $int_cast = (int) $x;
                </div>
                <div>
                    <h3>Math</h3>
                    <li>pi()</li>
                    <li>min(), max()</li>
                    <li>abs()</li>
                    <li>sqrt()</li>
                    <li>round</li>
                    <li>rand()</li>
                </div>
                <div>
                    <h3>Constants</h3>
                    define(name, value, case-insensitive(true or false));<br>
                    const name = value;
                </div>
            </ul>
        </div>
    </div>

    </body>
</html>
