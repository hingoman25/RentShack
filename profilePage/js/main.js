'use strict';


var playersRef = firebase.database().ref("/posts");


function snapshotToArray(snapshot) {
    var returnArr = [];

    snapshot.forEach(function(childSnapshot) {
        var item = childSnapshot.val();
        item.key = childSnapshot.key;

        returnArr.push(item);
    });

    return returnArr;
}


function deletePost(pid){
	
	firebase.database().ref('posts/' + pid).remove();
 	//window.location.replace("./profilePage.html");
}


firebase.database().ref('/posts').on('value', function(snapshot) {
    	var arr = snapshotToArray(snapshot);
	    var rentList = document.getElementById('rentList');
	    var uid = firebase.auth().currentUser.uid;
	    rentList.innerHTML = '';

		for(var i = arr.length-1; i >= 0; i--) {
		 	if(uid == arr[i].uid) {
		       var title = arr[i].titlePost;
			   var desc = arr[i].itemDescription;
			   var img = arr[i].imageURL;
			   var price = arr[i].pricePerHour;
 var pid = arr[i].pid;


	   rentList.innerHTML += 
		   '<p href="./profilePage.html" onClick="deletePost(\''+ pid +'\')" id="trash" >X</p>' +
		   '<a id="anchor" style="text-decoration:none" style="display:block" href="../itemPage/itemPage.html?pid=' + pid + '">' +
						   '<div  class="col-md-offset-2">' +
						                '<div class="col-12 col-lg-4">' +
						                    '<div class="card features">' +
						                        '<div class="card-body">' +
						                            '<div class="media">' +
														'<img href="#" class="renting" id="image" src=' + img + ' class="listpics" alt="">' +
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

	}
});




