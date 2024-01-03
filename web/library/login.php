<html>
    <head>
        <style>
            body {
                margin: 100px;
                text-align: center;
                font-family: sans-serif;
                background-color: #B4D4FF;
            }
            input[type="text"], input[type="password"] {
                height: 30px;
                margin: 5px;
                width: 80%;
                border-radius: 5px;
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
        <h1>Login</h1>
        <form action="add.php" method="post">
            Username: <input type="text" name="username"><br>
            Password: <input type="password" name="password"><br>
            <input type="submit" value="Login" name="login">
        </form>
    </body>
</html>