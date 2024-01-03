<html>
    <head>
        <style>
            .title {
                margin-right: 900px;
            }
            .loggedin {
                margin: 10px;
            }
        </style>
    </head>
    <body>
        <table>
            <tr>
                <td>
                    <div class="title"><h1>Library</h1></div>
                </td>
                <?php 
                    session_start();
                    if (isset($_SESSION['username'])) {
                        echo "
                    <td>
                        <div class='loggedin'><h>Logged In: {$_SESSION['username']}</h3></div>
                    </td>";
                    }
                ?>
                <td><a href="login.php" target="main">Login</a></td>
                <td><a href="add.php" target="main">Add Books</a></td>
            </tr>   
    </body>
</html>