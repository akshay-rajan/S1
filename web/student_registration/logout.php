<html>
    <head>
        <style>
            body {
                background-color: #F5F5F5;
                margin: 50px;
                display: flex;
                justify-content: center;
                text-align: center;
            }
            h1 {
                color: #364F6B;
            }
        </style>
    </head>
    <body>
        <?php
            session_start();
            session_destroy();
            echo "<h1>Logged Out Successfully!</h1>";
        ?>
    </body>
</html>