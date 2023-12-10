<html>
    <head>
        <title>PHP Forms</title>
    </head> 
    <body>
        <li>$_POST['name'];</li>
        <li>$_GET['name'];</li>
        <div>
            <h3>Form Validation</h3>
            <pre>$name = $email = $gender = $comment = $website = "";

            if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $name = test_input($_POST["name"]);
            $email = test_input($_POST["email"]);
            $website = test_input($_POST["website"]);
            $comment = test_input($_POST["comment"]);
            $gender = test_input($_POST["gender"]);
            }

            function test_input($data) {
            $data = trim($data);
            $data = stripslashes($data);
            $data = htmlspecialchars($data);
            return $data;
            }</pre>

            <h3>Form Required</h3>
            <pre>$nameErr = $emailErr = $genderErr = $websiteErr = "";
                $name = $email = $gender = $comment = $website = "";

                if ($_SERVER["REQUEST_METHOD"] == "POST") {
                if (empty($_POST["name"])) {
                    $nameErr = "Name is required";
                } else {
                    $name = test_input($_POST["name"]);
                }

                if (empty($_POST["email"])) {
                    $emailErr = "Email is required";
                } else {
                    $email = test_input($_POST["email"]);
                }

                if (empty($_POST["website"])) {
                    $website = "";
                } else {
                    $website = test_input($_POST["website"]);
                }

                if (empty($_POST["comment"])) {
                    $comment = "";
                } else {
                    $comment = test_input($_POST["comment"]);
                }

                if (empty($_POST["gender"])) {
                    $genderErr = "Gender is required";
                } else {
                    $gender = test_input($_POST["gender"]);
                }
                }
            </pre>
            <a href="https://www.w3schools.com/php/php_form_url_email.asp">Validation</a>
        </div>
    </body>
</html>