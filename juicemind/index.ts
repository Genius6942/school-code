import { initializeApp } from "firebase/app";
import { getAuth } from "firebase/auth";
import { getFirestore } from "firebase/firestore";
import { getStorage } from "firebase/storage";
import { getDatabase, ref, get, orderByKey, limitToFirst, query } from "firebase/database";
import fs from "node:fs";

// Your Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyBQxN5hUH9HCpvmFZ7rmeYPMprdle_3GsQ",
  authDomain: "play.juicemind.com",
  projectId: "juicemind-a9d9e",
  storageBucket: "juicemind-a9d9e.appspot.com",
  messagingSenderId: "1043717487308",
  appId: "1:1043717487308:web:60faa200f20f45cfa0e069",
  measurementId: "G-FGRLNTRZ5L",
  databaseURL: "https://juicemind-a9d9e-default-rtdb.firebaseio.com",
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);

// Get Firebase services (only import what you need)
const auth = getAuth(app);
const db = getFirestore(app);
const storage = getStorage(app);
const database = getDatabase(app);

const fetchAndWriteData = async () => {
  const dbRef = ref(database, "teams");
  const keysQuery = query(dbRef, );

  try {
    const snapshot = await get(keysQuery);
    if (snapshot.exists()) {
      const data = snapshot.val();

      // Write to db.json with 2 spaces of indentation
      fs.writeFileSync("db.json", JSON.stringify(data, null, 2));
      console.log("Database written to db.json successfully.");
    } else {
      console.log("No data available at the root.");
    }
  } catch (error) {
    console.error("Error fetching or writing data:", error);
  }
};

// Call the function
await fetchAndWriteData();

// const rootRef = ref(
//   storage,
//   "uploadTeamsFiles/05lnA7Aj7wkR76TYsOhu/c730ff9c-d13b-4bbe-86e4-5f047af7c200/7cb9f921-b1ba-4ed3-8388-1e061285f9de"
// );

// try {
//   const result = await listAll(rootRef);

//   result.items.forEach((itemRef) => {
//     console.log("File:", itemRef.fullPath);
//   });

//   result.prefixes.forEach((folderRef) => {
//     // const name = folderRef.fullPath.replace('teams/', '');
//     console.log("Directory:", folderRef.fullPath);
//   });
// } catch (error) {
//   console.error("Error listing root directory files:", error);
// }

// const downloadFile = async (filePath: string) => {
//   const fileRef = ref(storage, filePath);

//   try {
//     const url = await getDownloadURL(fileRef);
//     console.log("Download URL:", url);
//   } catch (error) {
//     console.error("Failed to download file:", error);
//   }
// };

// // Example usage
// await downloadFile(
//   "uploadTeamsFiles/05lnA7Aj7wkR76TYsOhu/c730ff9c-d13b-4bbe-86e4-5f047af7c200/7cb9f921-b1ba-4ed3-8388-1e061285f9de/6427031d-6a39-444f-b4ca-29c4c50178e3"
// );
