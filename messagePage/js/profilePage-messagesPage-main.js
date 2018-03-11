//  // Initialize Firebase
'use-strict';

var senderUID;
var receiverUID;
var global_convoID;

var message = document.getElementById('userMessage');
var messageForm = document.getElementById('messageForm');
// /*alert('THIS IS A FUCKING ALERT');*/



// 	document.getElementById('anchor').addEventListener("click", sendInstancePID() );
 


// 	function sendInstancePID() {
// 		alert('I HAVE BEEN CALLED');
// 	}



function assignUIDS(global_uid) {

	firebase.auth().onAuthStateChanged(function(user) {
		senderUID = user.uid;
		receiverUID = global_uid;

		console.log(senderUID + ' is trying to message ' + receiverUID);
		
		localStorage.setItem("senderUID", senderUID);
		localStorage.setItem("receiverUID", receiverUID);

		
		writeNewConversation();
	});
	
		
}



function writeNewConversation() {

  // Get a key for a new Post.
  var newConversationKey = firebase.database().ref().child('users/' + senderUID).push().key;
  
	firebase.database().ref('/users/' + senderUID).once('value').then(function(snapshot) {
		var username1 = (snapshot.val() && snapshot.val().username);
		var profilePic1 = (snapshot.val() && snapshot.val().profilePic) || '../images/user.png';
			firebase.database().ref('/users/' + receiverUID).once('value').then(function(snapshot) {
				var username2 = (snapshot.val() && snapshot.val().username);
				var profilePic2 = (snapshot.val() && snapshot.val().profilePic) || '../images/user.png';

	// A post entry.
  var conversationData = {
	  uid1: senderUID,
	  uid2: receiverUID,
	  cid: newConversationKey,
	  username1: username1,
	  username2: username2,
	  profilePic1: profilePic1,
	  profilePic2: profilePic2
	  
    //starCount: 0, PERHAPS ADD ITEMAVALIABILITY VARIABLE??? 
  };
  // Write the new post's data simultaneously in the posts list and the user's post list.
  var updates = {};
  updates['/users/' + senderUID + '/conversations/' + newConversationKey] = conversationData;
  updates['/users/' + receiverUID + '/conversations/' + newConversationKey] = conversationData;

	firebase.database().ref('users/' + senderUID + '/conversations/' + newConversationKey + '/').remove();
	firebase.database().ref('users/' + receiverUID + '/conversations/' + newConversationKey + '/').remove();
	convoID = newConversationKey;

		//firebase.database().ref('posts/' + pid).remove();

	window.location.assign("../messagePage/messagePage.html?convoid=" + newConversationKey);

	
  return firebase.database().ref().update(updates);
		});
  });
}

function formatAMPM(date) {
  var hours = date.getHours();
  var minutes = date.getMinutes();
  var ampm = hours >= 12 ? 'pm' : 'am';
  hours = hours % 12;
  hours = hours ? hours : 12; // the hour '0' should be '12'
  minutes = minutes < 10 ? '0'+minutes : minutes;
  var strTime = hours + ':' + minutes +  ampm;
  return strTime;
}


function writeNewMessage(uid, username, message) {


  // Get a key for a new Post.
  var newMessageKey = firebase.database().ref().child('users/' + senderUID).push().key;
  
	var d = new Date();
	var date = formatAMPM(d);
	// A post entry.
  var messageData = {
	  uid: uid,
	  username: username,
	  message: message,
	  time: date
	 // isRead: false
    //starCount: 0, PERHAPS ADD ITEMAVALIABILITY VARIABLE??? 
  };
  // Write the new post's data simultaneously in the posts list and the user's post list.
  var updates = {};
  updates['users/' + currentUID + '/conversations/' + global_convoID + '/' + newMessageKey] = messageData;
  updates['users/' + receiverUID + '/conversations/' + global_convoID + '/' + newMessageKey] = messageData;
	//alert('user ' + localStorage.getItem("senderUID"));
	
	
  return firebase.database().ref().update(updates);
}
  var currentUID;


function onAuthStateChanged(user) {
  // We ignore token refresh events.
  if (user && currentUID === user.uid) {
    return;
  }

  //cleanupUi();
  if (user) {

    currentUID = user.uid;
    //splashPage.style.display = 'none';
    //writeUserData(user.uid, user.displayName, user.email, user.photoURL);
    //startDatabaseQueries();
  } else {
    // Set currentUID to null.
    currentUID = null;
    // Display the splash page where you can sign-in.
    //splashPage.style.display = '';
  }
}

function newMessageForCurrentUser(message) {
  var userId = firebase.auth().currentUser.uid;
  return firebase.database().ref('/users/' + userId).once('value').then(function(snapshot) {
    var username = (snapshot.val() && snapshot.val().username);
	 // var profilePic = (snapshot.val() && snapshot.val().profilePic)
    return writeNewMessage(firebase.auth().currentUser.uid, username, message);;
  });

}


window.addEventListener('load', function() {
  // Bind Sign in button.
 /* signInButton.addEventListener('click', function() {
    var provider = new firebase.auth.GoogleAuthProvider();
    firebase.auth().signInWithPopup(provider);
  }); */

  // Bind Sign out button.
 /* signOutButton.addEventListener('click', function() {
    firebase.auth().signOut();
  }); */

	global_convoID = sliceConvoID();
	
	
	firebase.auth().onAuthStateChanged(function(user) {
	  if (user) {
		// User is signed in.
		  firebase.database().ref('/users/' + user.uid + '/conversations/' + global_convoID + '/').once('value').then(function(snapshot) {
			var uid;
			var uid1 = (snapshot.val() && snapshot.val().uid2);
			var uid2 = (snapshot.val() && snapshot.val().uid1);
			  
			  if(user.uid == uid1)
				  { uid = uid2; }
			  else
				  { uid = uid1; }
			  
			firebase.database().ref('/users/' + uid).once('value').then(function(snapshot) {
				
				var username = (snapshot.val() && snapshot.val().username);
				var uid = (snapshot.val() && snapshot.val().uid);
				receiverUID = uid;
				document.getElementById("messagesHeader").innerHTML = "Messaging " + username;
				

			});
		});
	  } else {
		// No user is signed in.
	  }
	});
	
	/*firebase.database().ref('/users/' + localStorage.getItem("receiverUID") + '/conversations/' + global_convoID + '/').once('value').then(function(snapshot) {
		
			var uid1 = (snapshot.val() && snapshot.val().uid1);
			firebase.database().ref('/users/' + uid1).once('value').then(function(snapshot) {
				
				var username = (snapshot.val() && snapshot.val().username);
				alert(username);

			});
		
	});
*/
	
	
  // Listen for auth state changes
  firebase.auth().onAuthStateChanged(onAuthStateChanged);

  // Saves message on form submit.
  messageForm.onsubmit = function(e) {
    e.preventDefault();
    //var text = messageInput.value;
    //var title = titleInput.value;
	var messageVar = message.value;
	//var price = pricePerHour.value;
	//var description = itemDescription.value;
	//var condition = itemCondition.value;
	//var upload = fileUpload.value;
	
    //if (text && title) {
	  if ( messageVar ) {
      newMessageForCurrentUser(messageVar).then(function() {
       // myPostsMenuButton.click();
      });
      messageVar.value = '';

    }
  };
}, false);

function sliceConvoID() {
    var currentURL = window.location.href;
	var index = currentURL.indexOf("=" , 0) + 1;
	
	var convoID = "";
	for(var i = index; i < currentURL.length; i++)
	{
			
		convoID += currentURL.charAt(i);

	}
	global_convoID = convoID;
	return convoID;
}

