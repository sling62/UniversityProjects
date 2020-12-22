// Author: Samantha Ling 
// Date: 17/04/20 
// File Description: Firebase and necessary app assets are loaded here + react navigator is created to move between screens (different react classes)

import React from 'react';
import {Image} from 'react-native';

//A react native stack navigator has been used in this project, for more information see docs: https://reactnavigation.org/docs/
import { createAppContainer } from "react-navigation"; 
import { createStackNavigator } from 'react-navigation-stack'; 

//React native project has been created using expo, for more information see docs: https://docs.expo.io/versions/latest/

//expo font library is imported to load external fonts into the project
import * as Font from 'expo-font';
import { AppLoading } from 'expo'; //expo component which pre-loads assets before app starts

import firebase from 'firebase'; //installed and imported firebase packages into project

//importing react component classes to be used in react navigator 
import HomeScreen from './components/Home/HomeScreen';
import AboutScreen from './components/About/AboutScreen';
import SettingsScreen from './components/Settings/SettingsScreen';
import SearchScreen from './components/Search/SearchScreen';
import NotificationsScreen from './components/Notifications/NotificationsScreen';
import PrivacyScreen from './components/Privacy/PrivacyScreen';
import SupportScreen from './components/Support/SupportScreen';
import DefinitionScreen from './components/Definition/DefinitionScreen';


import {appLogo, font, loadingScreen} from './components/Constants.js'; //importing image and font routes from constants file
import styles from './components/Styles.js' //importing shared app styling

//Firebase Config: I Have removed API Key as well as database URL from below - REMOVE!
var config = {
  apiKey: "AIzaSyDIIDhmSWVlW6x52UBQEwrNBiK6tn0D8vs",
  authDomain: "wordlocator-app.firebaseapp.com",
  databaseURL: "https://wordlocator-app.firebaseio.com",
  storageBucket: "wordlocator-app"
};

//Initialising react native app with Firebase
if (!firebase.apps.length) {
  firebase.initializeApp(config);
}

export default class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      isReady: false, //State set to indicate when app is finished loading necessary assets
    };
  }

  render() {
    if (!this.state.isReady) {
      return (
        <AppLoading
          startAsync={this.loadAssetsAsync}  //pre-loads assets such as images and fonts
          onFinish={() => this.setState({ isReady: true })} //once finished the app will go to default navigator screen (Home)
          onError={console.warn}
        />
      ); 
    }
    return (
      <AppContainer/> //Creates navigator here 
    );
  }

  async loadAssetsAsync() {
    //loads Raleway font files from assets folder
    await Font.loadAsync({
      Raleway_Regular: font['ralewayRegular'],
      Raleway_Bold: font['ralewayBold'],
      Raleway_Italic: font['ralewayItalic']
    });

    this.setState({ isReady: true }); 
    
    const images = [loadingScreen]; //loading screen image (app logo) displayed 
    const cacheImages = images.map(image => {
      return Asset.fromModule(image).downloadAsync();
    }); 
    return Promise.all(cacheImages);
  }
}

//App Navigator (stack) which can be referenced throughout all screens (classes)
const AppNavigator = createStackNavigator(
  {
    Home: HomeScreen,
    Search: SearchScreen,
    Definition: DefinitionScreen,
    Settings: SettingsScreen,
    Notifications: NotificationsScreen,
    Privacy: PrivacyScreen,
    Support: SupportScreen,
    About: AboutScreen,
  },
  {
    initialRouteName: 'Home', //initial landing screen is set to Home
    defaultNavigationOptions : { //shared navigation header styling is set here (cannot be set in seperate stylesheet due to react navigation parameters), for more information please see: https://reactnavigation.org/docs/headers/
      headerTitle: () =>  <Image style={styles.appLogo} source={appLogo}/>,
      headerStyle: {
        height:130,
        backgroundColor: '#012060',
      },
      headerTintColor: '#FFFFFF'
    }
  }
);

const AppContainer = createAppContainer(AppNavigator);
