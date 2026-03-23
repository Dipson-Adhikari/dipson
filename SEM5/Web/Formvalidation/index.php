<?php

    // handle post request
    if($_SERVER['REQUEST_METHOD'] === 'POST'){
    
        $formData = $_POST;

        $registerdEmails = ['adhikaridipson007@gmail.com'];

        $name = htmlspecialchars(trim($formData['fullname'] ?? ''));
        $email = trim($formData['email'] ?? '');
        $password = trim($formData['password'] ?? '');
        $confirmPassword = trim($formData['confirmPassword'] ?? '');

        $errors = [];

        //name validation
        if($name === ''){
            $errors['fullname'] = 'Name is required';
        }

        if($name !== '' && strlen($name) < 3){
            $errors['fullname'] = 'Name must be at least 3 characters';
        }

        //email validation
        if($email === ''){
            $errors['email'] = 'Email is required';
        }

        if($email !== '' && filter_var($email, FILTER_VALIDATE_EMAIL) === false){
            $errors['email'] = 'Invalid email format';
        }

        if($email !== '' && in_array($email, $registerdEmails)){
            $errors['email'] = 'Email is already registered';
        }

        //password validation
        if($password === ''){
            $errors['password'] = 'Password is required';
        }

        if ($password !== '' && strlen($password) < 6){
            $errors['password'] = 'Password must be at least 6 characters';
        }

        //confirm password validation
        if($password !== $confirmPassword){
            $errors['confirmPassword'] = 'Passwords do not match';
        }


        if( empty($errors) ){
            //form is valid. Proceed 
            echo "Form submitted successfully!";
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
        <form action="/index.php" name="registerForm" method="post">
            <h2>Create an account</h2>
            <div class="form-group">
                <label for="fullname">Name</label>
                <input type="text" class="<?= isset($errors['fullname']) ? 'error-input' : '' ?>" name="fullname" id="fullname">
                <span class="error-text" id="fullnameErrorText">
                    <?= isset($errors['fullname']) ? $errors['fullname'] : '' ?>
                </span>
            </div>

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

            <div class="form-group">
                <label for="confirmPassword">ConfirmPassword</label>
                <input type="password" class="<?= isset($errors['confirmPassword']) ? 'error-input' : '' ?>" name="confirmPassword" id="confirmPassword">
                <span class="error-text" id="confirmPasswordErrorText">
                    <?= isset($errors['confirmPassword']) ? $errors['confirmPassword'] : '' ?>
                </span>
            </div>


            <button type="submit" class="registerBtn">Register</button>
        </form>
    </div>

 
</body>
</html>