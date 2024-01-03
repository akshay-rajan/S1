<html>
    <head>
        <style>
            body {
                margin: 100px;
                text-align: center;
                background-color: #D5F0C1;
                font-family: sans-serif;
            }
            input[type="text"], select {
                height: 30px;
                margin: 5px;
                width: 80%;
                border-radius: 5px;
            }
            select {
                width: 50%;
            }
            input[type="submit"] {
                width: 20%;
                height: 30px;
                border-radius: 5px;
                background-color: #176B87;
                color: white;
            }
            h1 {
                background-color: #176B87;
                color: white;
            }
        </style>
    </head>
    <body>
        <h1>Add Book</h1

        <?php
            session_start();    
            $conn = mysqli_connect('localhost', 'root', '', 'library');
            if (!$conn)
                echo mysqli_error($conn);
            else {
                if (isset($_POST['login'])) {
                    $username = $_POST['username'];
                    $password = $_POST['password'];

                    $sql = "SELECT * FROM users WHERE username = '$username' AND password = '$password'";
                    $result = mysqli_query($conn, $sql);
                    if (mysqli_num_rows($result) > 0) {
                        $_SESSION['username'] = $username;
                        echo "
                        
                        <form action='' method='post'>
                        Title  :        <input type='text' name='title'><br>
                        Author:       <input type='text' name='author'><br>
                        No. of copies:
                        <select name='copies'>
                            <option value='SELECT' selected disabled>SELECT</option>";
                                for ($i = 10000; $i < 1000000; $i += 10000) {
                                    echo "<option value='{$i}'>{$i}</option>";
                                }
                        echo "</select><br>
                        <input type='submit' value='Add' name='add'>
                    </form>";
                    } else {
                        echo "<h2>User not found!</h2>";
                    }
                }
            }
        ?>

        <?php 
            if (isset($_POST["add"])) {
                $name = $_POST['title'];
                $author = $_POST['author'];
                $copies = $_POST['copies'];
                $sql = "INSERT INTO book (name, author, copies) VALUES ('$name', '$author', '$copies')";
                $result = mysqli_query($conn, $sql);
                if ($result) {
                    echo "<h2>Book Added Successfully!</h2>";
                } else {
                    echo mysqli_error($conn);
                }
            }
        ?>
    </body>
</html>