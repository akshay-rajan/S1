<!DOCTYPE html>
<html>
    <head>
        <title>php</title>
        <style>
            body {
                padding: 20px;
                color: black;
                background-color: #ECF4D6;
            }
            h2, h3, h4 {
                color: #265073;
                background-color: #9AD0C2;
            }
        </style>
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
                    <pre>$int_cast = (int) $x;</pre>
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
                    <h3>Magic Constants</h3>
                    <li>__CLASS__ : name of the class</li>
                    <li>__DIR__: directory</li>
                    <li>__FILE__: filename</li>
                    <li>__FUNCTION__: function name</li>   
                    <li>__METHOD__: class and function name</li>
                </div><br>
                <div>
                    <h3>Operators</h3>
                PHP contains Arithmetic operators (+, -, *, /, %, **), Assignment operators (=, +=, /=, %=,...), 
                    Comparison Operators (==, ===, != or <>, >, <, >=, <=, <=> {to find the max/min}), Increment/decrement operators (++, --, ...) etc.
                    <li>and, &&</li>
                    <li>or, ||</li>
                    <li>xor: true if only one is true and not both</li>
                    <li>!</li>
                    <li>.: concatenation in string</li>
                    <li>.=: concatenation assignment-- $a .= $b appends $b to $a</li>
                    <li>Array Operators: +(Union), ==(Equality), ===(Identity~order), != etc.</li>
                    <li>Conditional: 1. Ternary: $x = condition? if_true; if_false;<br>
                        2. Null coalescing: $x = if_this_exists?? if_that_does_not_exist;
                    </li>
                </div>
                <div>
                    <h3>Conditional Statements</h3>
                    <pre>
                        if (condition) {
                            code;
                        } elseif (codition) {
                            code;
                        } else {
                            code;
                        }
                </div>
                <div>
                    <h3>Switch</h3>
                    <pre>
                    switch (n) {
                        case label1:
                            code;
                            break;
                        case label2:
                            code;
                            break;
                        case label3:
                            code;
                            break;
                            ...
                        default:
                            code;
                        } 
                </div>
                <div>
                    <h3>Loops</h3>
                    <h4>While</h4>
                    <pre>
                        while (condition) {
                            code;
                        }
                    </pre>
                    <h4>do while</h4>
                    <pre>
                        do {
                            code;
                        } while (condition);
                    </pre>
                    <h4>For</h4>
                    <pre>
                        for ($i = 0; $i < 100; $i++) {
                            echo i;
                        }
                    </pre>
                    <h4>Foreach: for arrays</h4>
                    <pre>
                        $colors = array("red", "green", "blue", "yellow");

                        foreach ($colors as $value) {
                            echo "$value";
                        }
                    </pre>
                    <li>break: to exit the loop</li>
                    <li>continue: to skip the current iteration</li>
                </div>
                <div>
                    <h3>Functions</h3>
                    <pre>
                        function func_name($argument) {
                            code;
                        }
                    </pre>
                    <li>Default argument values can be included in the function definition by <pre>($arg = value)</pre></li>
                    <li>We can even return a function call</li>
                    <li>Pass by reference is also available, to update a variable</li>
                    <pre>
                        function add_five(&$value) {
                            $value += 5;
                        }

                        $num = 2;
                        add_five($num);
                    </pre>
                </div>
                <div>
                    <h3>Array</h3>
                    <li>In php, the array() function is used to create an array.</li>
                    <li>Indexed Array:</li>
                        <pre>
                            $car = array('bmw', 'honda', 'toyota');
                        </pre>
                    We can use the 'count()' function to find the length of the array.
                    <li>Associative Array (like dictionary in python):</li>
                        <pre>
                            $age = array("a"=>"5", "b"=>"7");
                        </pre>
                    <li>Multidimensional arrays: arrays inside an array</li>
                    We can use functions like sort(), rsort(), asort() etc. to sort different kinds of arrays.
                </div>
                <div>
                    <h3>SuperGlobals</h3>
                    Some predefined variables in php, that are always accessible from anywhere.
                    <li>$GLOBALS : To access global variables from anywhere</li>
                        <pre>
                            $x = 5;
                            $y = 7;
                            function addition($x, $y) {
                                $GLOBALS['z'] = $GLOBALS['x'] + $GLOBALS['y'];
                            }
                            echo "$z";
                        </pre>
                    <li><a href="https://www.w3schools.com/php/php_superglobals_server.asp">$_SERVER : Holds info about headers, paths, and script locations.</a></li>
                        <pre>
                        echo $_SERVER['PHP_SELF']; // Filename
                        echo $_SERVER['SERVER_NAME'];
                        echo $_SERVER['HTTP_HOST'];
                        echo $_SERVER['HTTP_REFERER'];
                        echo $_SERVER['HTTP_USER_AGENT'];
                        echo $_SERVER['SCRIPT_NAME'];
                        </pre>
                    <li>$_REQUEST : To collect data from a form submission</li>
                        <pre>
                            $name = $_REQUEST['name'];
                        </pre>
                    <li>$_POST : To collect data from a form submission via POST method</li>
                    <li>$_GET : To collect data from a form submission via GET (from url)</li>
                </div>
                <div>
                    <h3>RegEx-- Regular Expression</h3>
                    Regular expressions are patterns containing delimeters (/), a pattern and optional modifiers (i)
                    <pre>
                        $str = "Visit W3Schools";
                        $pattern = "/w3schools/i";
                        echo preg_match($pattern, $str); // Outputs 1
                    </pre>
                    There are several functions associated with regular expressions.<br>
                    Many <a href="https://www.w3schools.com/php/php_regex.asp">Modifiers, Patterns, Metacharacters and Quantifiers</a> are present in php.
                </div>
            </ul>
        </div>
    </div>

    </body>
</html>
