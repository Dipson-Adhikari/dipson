<?php
    session_start();

    if(isset($_SESSION['userIsLogin']) && $_SESSION['userIsLogin']==true)
        {
            header('Location: /home.php');
        }
    //set cookie using php
    // setcookie("email","dipson11@gmail.com",time() + 86400);

    // $cookies =$_COOKIE;
    // print_r($cookies);

    $_SESSION['isLogin']=true;

    // handle post request


    if($_SERVER['REQUEST_METHOD'] === 'POST'){
    
        $formData = $_POST;

        $registerdUser= [
            'adhikaridipson007@gmail.com'=>'dipson1122'
        ];

        $email = trim($formData['email'] ?? '');
        $password = trim($formData['password'] ?? '');

        $errors = [];


        //email validation
        if($email === ''){
            $errors['email'] = 'Email is required';
        }else if(filter_var($email, FILTER_VALIDATE_EMAIL) === false){
            $errors['email'] = 'Invalid email format';
        }
        else if(!in_array($email, array_keys($registerdUser))){
            $errors['email'] = 'Email is not registered';
        }


        //password validation
        if($password === ''){
            $errors['password'] = 'Password is required';
        }

        if ($password !== '' && strlen($password) < 6){
            $errors['password'] = 'Password must be at least 6 characters';
        }


        if( empty($errors) ){
            //form is valid. Proceed 

            // check password
            if($registerdUser[$email] === $password){
                $_SESSION['userIsLogin'] = true;
                header("Location: /home.php");
                exit;
            } else {
                $errors['password'] = "Password is incorrect";
            }
        }
    
    }






?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration Form</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <form action="/login.php" name="registerForm" method="post">
            <h2>Login to your account</h2>

            <div class="form-group">
                <label for="email">Email</label>
                <input type="text" class="<?= isset($errors['email']) ? 'error-input' : '' ?>" name="email" id="email">
                <span class="error-text" id="emailErrorText">
                    <?= isset($errors['email']) ? $errors['email'] : '' ?>
                </span>
            </div>

            <div class="form-group">
                <label for="password">Password</label>
                <input type="password" class="<?= isset($errors['password']) ? 'error-input' : '' ?>" name="password" id="password">
                <span class="error-text" id="passwordErrorText">
                    <?= isset($errors['password']) ? $errors['password'] : '' ?>
                </span>
            </div>


            <button type="submit" class="registerBtn">Login</button>
        </form>
    </div>

    <!-- <script src="./script.js"></script> -->
</body>
</html>