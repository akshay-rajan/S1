<html>
    <body>
        <form action="" method="post">
            Username: <input type="text" name="username"><br>
            Password: <input type="password" name="password">
            <input type="submit" value="Login" name="login">
        </form>
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
                        echo "<h1>Logged In!</h1>";
                    } else {
                        echo "<h2>User not found!</h2>";
                    }
                }
            }
        ?>
    </body>
</html>