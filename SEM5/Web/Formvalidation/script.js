

const registerForm = document.forms.registerForm;
const fullNameElement = registerForm.fullname;
const emailElement = registerForm.email;
const passwordElement = registerForm.password;
const confirmPasswordElement = registerForm.confirmPassword;

registerForm.addEventListener('submit', function (event) {
    event.preventDefault();

    let isvalid = true;

    function showError(elementName, errorMsg){
        const errorElement = document.getElementById(elementName + 'ErrorText');
        const element = registerForm[elementName];
        element.classList.add('error-input');
        errorElement.innerText = errorMsg;
        isvalid = false;
        
    }

    //NAME validation
    if(fullNameElement.value == ""){
        showError("fullname", "Name is required");
    }


    //email validation
    if(emailElement.value == ""){
        showError("email", "Email is required");
    }
    else if(/^\w+@\w+\.\w{2,3}$/.test(emailElement.value) === false){
        showError("email", "Invalid email address");
    }

    //password validation
    if(passwordElement.value == ""){
        showError("password", "Password is required");
    }
    else if(passwordElement.value.length < 8){
        showError("password", "Password must be at least 8 characters long");
    }

    //confirm password validation
    if(confirmPasswordElement.value == ""){
        showError("confirmPassword", "Confirm Password is required");
    }
    else if(confirmPasswordElement.value !== passwordElement.value){
        showError("confirmPassword", "Passwords do not match");
    }

    if(isvalid){
        alert("Form submitted successfully!");
        registerForm.reset();
    }
    

})