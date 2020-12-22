// Author: Samantha Ling 
// Date: 22/03/20 
// File Description: Screen to display a short version of the word of the day, and route to the word of the day (Definition Screen), Search Screen and Settings Screen 

import React, { Component } from 'react';
import { View, Text, Image } from 'react-native'; 

// native base package is installed and Button and Icon elements are imported, for more information please see: https://docs.nativebase.io/
import { Button, Icon } from 'native-base'; 

//importing screen text and image routes from constants file
import {
  screenTitles, 
  appLogo, 
  settingsIcon, 
  searchIcon, 
  searchButtonText, 
  punctuation, 
  definitionNumber
} from '../Constants.js' 

import homeStyles from './Styles.js' //importing styling specific to home screen
import styles from '../Styles.js' //importing shared app styling



export default class Homescreen extends Component {
  constructor(props) {
    super(props);

    //state to hold the word of the day details fetched from Firebase
    this.state = {
      word: null,
      pronunciation: null,
      action: null,
      definition: null,
      example: null,
      otherdefinition: null,
      otherexample: null,
      firstrelatedword: null,
      secondrelatedword: null,
      thirdrelatedword: null,
      fourthrelatedword: null,
      audiopath: null
    };
    this.arrayholder = [];  //temporary array holder to hold JSON objects fetched from Firebase
  }

  //React Navigation styling set here to incorperate settings (overides default settings set in App.js)
  static navigationOptions = ({navigation}) => {
    return {
      headerTitle: () =>  <Image style={[styles.appLogo, homeStyles.appLogo]} source={appLogo}/>,
      headerStyle: {
        height:130,
        backgroundColor: '#012060',
      },
      headerRight: () => (
        <Button transparent onPress={() => navigation.navigate('Settings')}> 
          <Icon name={settingsIcon} style={homeStyles.settingsIcon} />
        </Button>
      ),
    }
  }

  //as soon as the Home Screen component mounts, a get request is made to fetch all words from Firebase
  componentDidMount() {
    this.makeRemoteRequest();
  }

  makeRemoteRequest = () => {
    const url = `https://wordlocator-app.firebaseio.com/.json`; //url to .json script in Firebase
 
    fetch(url)
      .then(res => res.json())
      .then(res => {
        //once results are fetched, this is placed in an array where each array element is a word record
        this.arrayholder = res.results; 
        //a random word record is chosen from the array to be the word of the day
        let item = this.arrayholder[Math.floor(Math.random() * this.arrayholder.length)].definition; 

        //the word record fields (name of word, ponunciation, definition etc.) are set in state. (there are checks to make sure the word record is not null)
        this.setState({
          word: item.name ? item.name : null,
          pronunciation: item.pronunciation ? item.pronunciation : null,
          action: item.action ? item.action : null,
          definition: item.description ? item.description : null,
          example: item.example ? item.example : null,
          otherdefinition: item.otherdescription ? item.otherdescription : null,
          otherexample: item.otherexample ? item.otherexample : null,
          firstrelatedword: item.firstrelatedword ? item.firstrelatedword : null,
          secondrelatedword: item.secondrelatedword ? item.secondrelatedword : null,
          thirdrelatedword: item.thirdrelatedword ? item.thirdrelatedword : null,
          fourthrelatedword: item.fourthrelatedword ? item.fourthrelatedword : null,
          audiopath: item.audiopath ? item.audiopath : null,
        });
      })
  };

  render() {
    //word of the day fields are fetched from state to be passed to the Definition Screen route (where it displays the full word' fields)
    const wordOfTheDay = {
      name: this.state.word,
      definition: this.state.definition,
      pronunciation: this.state.pronunciation,
      action: this.state.action,
      example: this.state.example, 
      otherdefinition: this.state.otherdefinition,
      otherexample: this.state.otherexample,
      firstrelatedword: this.state.firstrelatedword,
      secondrelatedword: this.state.secondrelatedword,
      thirdrelatedword: this.state.thirdrelatedword,
      fourthrelatedword: this.state.fourthrelatedword,
      audiopath: this.state.audiopath
    }

    //Button routes to Search Screen(when search bar is clicked) or Definition Screen (for the word of the day when it is clicked)
    return (
      <View>
        <View style = {styles.searchContainer}>
          <View style={styles.searchBar}>
            <Button iconLeft onPress={() => this.props.navigation.navigate('Search')} style={styles.searchBox}>
              <Icon style={styles.search} name={searchIcon} /> 
              <Text style={[styles.search, styles.searchPlaceholder]}>
                {searchButtonText} 
              </Text>
            </Button>
          </View>
        </View>
        <View style = {styles.appStyling}>
          <Text style={styles.heading}>  
            {screenTitles['WordOfTheDay']}
          </Text>
        </View>
        <View style={homeStyles.wordOfTheDayContainer}>
          <Button transparent style={homeStyles.button} onPress={() => this.props.navigation.navigate('Definition', wordOfTheDay)}>
            <Text style={[homeStyles.wordOfTheDay,homeStyles.wordOfTheDayHeading]}> 
              {wordOfTheDay['name']}
            </Text>
          </Button>
          <Button transparent style={homeStyles.button} onPress={() => this.props.navigation.navigate('Definition', wordOfTheDay)}>
            <Text style={[homeStyles.wordOfTheDay,homeStyles.wordOfTheDayPronunciation]}> 
              {punctuation['openSquareBracket']}{wordOfTheDay['pronunciation']}{punctuation['closeSquareBracket']}
            </Text>
          </Button>
          <Button transparent style={homeStyles.button} onPress={() => this.props.navigation.navigate('Definition', wordOfTheDay)}>
            <Text style={[homeStyles.wordOfTheDay,homeStyles.wordOfTheDayAction]}> 
              {punctuation['dash']}{wordOfTheDay['action']}
            </Text>
          </Button>
          <Button transparent style={homeStyles.button} onPress={() => this.props.navigation.navigate('Definition', wordOfTheDay)}>
            <Text style={[homeStyles.wordOfTheDay,homeStyles.wordOfTheDayDefinition]}> 
              {definitionNumber['one']} {wordOfTheDay['definition']}
            </Text>
          </Button>
          <Button transparent style={homeStyles.button} onPress={() => this.props.navigation.navigate('Definition', wordOfTheDay)}>
            <Text style={[homeStyles.wordOfTheDay,homeStyles.wordOfTheDayExample]}> 
              {punctuation['speechMark']}{wordOfTheDay['example']}{punctuation['speechMark']}
            </Text>
          </Button>
        </View>
      </View>
    )
  }
}

