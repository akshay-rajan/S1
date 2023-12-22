<html>
    <head>
        <style>
            body {
                font-family: Arial, Helvetica, sans-serif;
                background-color: #F5F5F5;
                margin: 50px;
                display: flex;
                justify-content: center;
                text-align: center;
            }
            h1 {
                font-size: 40px;
                color: #364F6B;
            }
        </style>
    </head>
    <body>
        <?php
            session_start();
            session_destroy();
        ?>
        <div>
            <h1>Logged Out Successfully!</h1>
            <a href="login.php">Login</a> or <a href="register.php">Register</a>
        </div>
    </body>
</html>