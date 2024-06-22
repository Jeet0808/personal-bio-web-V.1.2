// methode 1
// let modebtn = document.querySelector("#mode");
// let currentmode = "light";

// modebtn.addEventListener("click", () => {
//     if (currentmode === "light") {
//         currentmode = "dark";
//         document.querySelector("body").style.backgroundColor = "rgb(71, 5, 5)";
//     }
//     else{
//         currentmode = "light";
//         document.querySelector("body").style.backgroundColor = "rgb(238, 198, 198)";
//     }
//     console.log(currentmode);
// });
// methode 2
let modebtn = document.querySelector("#mode");
let body = document.querySelector("body");
let photo = document.querySelector("#photo");
let photo2 = document.querySelector("#photo2");



let currentmode = "light";

modebtn.addEventListener("click", () => {
    if (currentmode === "light") {
        currentmode = "dark";
       body.classList.add("dark");
       photo.classList.add("dark");
       photo2.classList.add("dark");
       
       
       body.classList.remove('light');
     
       photo.classList.remove('light');
       photo2.classList.remove('light');
       
       document.querySelector("#id2").style.color = "bisque";
       document.querySelector("#p1").style.color = "bisque";
       
    }
    else{
        currentmode = "light";
        body.classList.add("light");
        photo.classList.add("light");
        photo2.classList.add("light");
        body.classList.remove('dark');
       
        photo.classList.remove('dark');
        photo2.classList.remove('dark');
       
        document.querySelector("#id2").style.color = "rgb(41, 8, 8)";
        document.querySelector("#p1").style.color = "rgb(41, 8, 8)";

       
    }
    console.log(currentmode);
});