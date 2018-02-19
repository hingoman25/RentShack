'use strict';


var titlePost = document.getElementById('titlePost');
var itemDescription = document.getElementById('itemDescription');


// var playersRef = firebase.database().ref("/posts");

// playersRef.on("child_added", function(data, prevChildKey) {
//    var user = data.val();
//    console.log("title: " + user.titlePost);
//    console.log("description: " + user.itemDescription);

   

// });


function snapshotToArray(snapshot) {
    var returnArr = [];

    snapshot.forEach(function(childSnapshot) {
        var item = childSnapshot.val();
        item.key = childSnapshot.key;

        returnArr.push(item);
    });

    return returnArr;
}


firebase.database().ref('/posts').on('value', function(snapshot) {
    var arr = snapshotToArray(snapshot);
    console.log(arr);

    var rentList = document.getElementById('rentList');
    rentList.innerHTML = '';

    for(var i = 0; i < arr.length; i++) {
       var title = arr[i].titlePost;
	   var desc = arr[i].itemDescription;
	   var img = arr[i].imageURL;
	   var price = arr[i].pricePerHour;


	   rentList.innerHTML += 
		   '<a id="anchor" style="text-decoration:none" style="display:block" href="file:///C:/Users/Daddy/Desktop/rentshack/site/itemPage/itemPage.html">' +
						   '<div  class="col-md-offset-2">' +
						                '<div class="col-12 col-lg-4">' +
						                    '<div class="card features">' +
						                        '<div class="card-body">' +
						                            '<div class="media">' +
														'<img class="rentimg" id="image" src=' + img + 'class="listpics" alt="">' +
						                                '<div class="media-body">' +
						                                    '<h4 class="card-title" id="titlePost">' + title + '</h4>' +
															'<h5 id="price" class = "card-price">$' + price + '/hr</h5>' +
						                                    '<p class="card-text" id="itemDescription">' + desc + '</p>' +
						                                '</div>' +
						                            '</div>' +
						                        '</div>' +
						                    '</div>' +
						                '</div>' +
						            '</div>' +
			'</a>';

    }
});







// var titlePost = document.getElementById('titlePost').innerHTML =
//    user.titlePost;

//    var itemDescription = document.getElementById('itemDescription').innerHTML =
//    user.itemDescription;
   
//    document.getElementById('image').src = user.imageURL;

//    document.getElementById('price').innerHTML = "$" + user.pricePerHour + "/hour";


