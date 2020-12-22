// Author: Samantha Ling 
// Date: 04/04/20 
// File Description: Screen to display word definition of selected word from Home (ie. the word of the day) or Search Screen (from search results)

import React, { Component } from 'react';
import { View, Text } from 'react-native';
// native base package is installed and Button, Icon, ListItem, Left and Right position elements are imported, for more information please see: https://docs.nativebase.io/
import { Button, Icon, ListItem, Left, Right } from 'native-base'; 

// installing and importing expo-av Audio element to play word pronunciations, for more information please see: https://docs.expo.io/versions/latest/sdk/av/
import { Audio } from 'expo-av'; 

//importing screen text, image and audio routes from constants file
import { 
  audioPathList, 
  searchIcon, 
  searchButtonText, 
  volumeIcon, punctuation, 
  definitionNumber, 
  similarWordsText 
} from '../Constants'; 

import definitionStyles from './Styles.js' //importing styling specific to definition screen
import styles from '../Styles.js' //importing shared app styling

//creating a sound object to play audio
const soundObject = new Audio.Sound(); 

export default class definitionscreen extends Component {

  constructor(props) {
    super(props);
    this.arrayholder = []; //temporary array holder to hold JSON objects fetched from Firebase
  }

  getAudio = (name) => {
    return audioPathList[name]; //gets audiopath 
  };
  

  componentDidMount() {
    const { params } = this.props.navigation.state;//chosen word details passed as props from Home or Search Screen
    const name = params.name; //gets name of chosen word
    //by default the audio path will be set to the word hello audio path
    const audio = params.audiopath ? this.getAudio(name) : this.getAudio('hello'); 

    try {
      soundObject.loadAsync(audio); //tries loading audio from assets folder
    } catch (error) {
      console.log("An error occured loading audio")
    }
    this.makeRemoteRequest(); 
  }

  componentWillUnmount() {
    //unloads audio on current word definition, to play new audio (on new word definition)
    soundObject.unloadAsync(); 
  }

  makeRemoteRequest = () => {
    const url = `https://wordlocator-app.firebaseio.com/.json`; //url to .json script in Firebase
    fetch(url)
      .then(res => res.json())
      .then(res => {
        //once results are fetched, this is placed in an array where each array element is a word record
        this.arrayholder = res.results; 
      })
  };

  //function to filter for the similar word (to the current word) selected
  searchFilterFunction = (text) => {
    this.setState({
        value: text, 
    });

    //filters for the similar word selected
    const newData = this.arrayholder.filter(item => { 
        const itemData = `${item.definition.name.toUpperCase()}`;
        const textData = text.toUpperCase();
        return itemData.indexOf(textData) > -1;
    });
    const data = newData[0].definition; //gets the word record
  
    //pushes (and navigates) the details of the similar word to a new Definition Screen
    this.props.navigation.push('Definition', {
        name: data.name,
        definition: data.description,
        pronunciation: data.pronunciation,
        action: data.action,
        example: data.example,
        otherdefinition: data.otherdescription,
        otherexample: data.otherexample,
        firstrelatedword: data.firstrelatedword,
        secondrelatedword: data.secondrelatedword,
        thirdrelatedword: data.thirdrelatedword,
        fourthrelatedword: data.fourthrelatedword
    })
  };

  //removes quotes around returned jSON response eg. "hello" -> hello
  removeQuotes = (text) => {
    return (
      JSON.parse(JSON.stringify(text))
    );
  };


  render() {
    //fetches parameters of selected word passed to Definition Screen from Home or Search Screen route 
    const { params } = this.props.navigation.state;
    const name = params ? params.name : null;
    const definition = params ? params.definition: null;
    const pronunciation = params ? params.pronunciation: null;
    const action = params ? params.action: null;
    const example = params ? params.example: null;
    const otherdefinition = params ? params.otherdefinition: null;
    const otherexample = params ? params.otherexample: null;
    const firstrelatedword = params ? params.firstrelatedword: null;
    const secondrelatedword = params ? params.secondrelatedword: null;
    const thirdrelatedword = params ? params.thirdrelatedword: null;
    const fourthrelatedword = params ? params.fourthrelatedword: null;

    //renders search bar button (to take back to Search Screen) and word definition plus similar words
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
      <ListItem style = {definitionStyles.wordContainer}>
        <Left>
          <Text style={definitionStyles.wordHeader}> 
            {this.removeQuotes(name)}
          </Text>
        </Left>
        <Right>
          <Button iconRight transparent  onPress={() => soundObject.replayAsync()}>
            <Icon name={volumeIcon} style={definitionStyles.volumeIcon}/>
          </Button>
        </Right>
      </ListItem>
      <Text style={definitionStyles.wordPronunciation}> 
        {punctuation['openSquareBracket']}{this.removeQuotes(pronunciation)}{punctuation['closeSquareBracket']}
      </Text>
      <Text style={definitionStyles.wordAction}> 
        {punctuation['dash']}{this.removeQuotes(action)}
      </Text>
      <Text style={definitionStyles.wordDefinition}> 
        {definitionNumber['one']} {this.removeQuotes(definition)}
      </Text>
      <Text style={definitionStyles.wordExample}> 
        {punctuation['speechMark']}{this.removeQuotes(example)}{punctuation['speechMark']}
      </Text>
      {otherdefinition ? (
        <Text style={definitionStyles.wordDefinition}> 
          {definitionNumber['two']} {this.removeQuotes(otherdefinition)}
        </Text>
      ): (null)}
      {otherexample ? (
        <Text style={definitionStyles.wordExample}> 
          {punctuation['speechMark']}{this.removeQuotes(otherexample)}{punctuation['speechMark']}
        </Text>
      ): (null)}
      <Text style={definitionStyles.similarHeading}> 
        {similarWordsText}
      </Text>
      <View style={definitionStyles.container}>
        {firstrelatedword ? (
          <View style={definitionStyles.buttonContainer}>
            <Button rounded warning onPress={() => this.searchFilterFunction(this.removeQuotes(firstrelatedword))}>
              <Text style = {definitionStyles.buttonText}> 
                {this.removeQuotes(firstrelatedword)} 
              </Text>
            </Button>
          </View>
        ): (null)}
        {secondrelatedword ? (
          <View style={definitionStyles.buttonContainer}>
            <Button rounded warning onPress={() => this.searchFilterFunction(this.removeQuotes(secondrelatedword))}>
              <Text style = {definitionStyles.buttonText}> 
                {this.removeQuotes(secondrelatedword)} 
              </Text>
            </Button>
          </View>
        ): (null)}
      </View>
      <View style={definitionStyles.container}>
        {thirdrelatedword ? (
          <View style={definitionStyles.buttonContainer}>
            <Button rounded warning onPress={() => this.searchFilterFunction(this.removeQuotes(thirdrelatedword))}>
              <Text style = {definitionStyles.buttonText}> 
                {this.removeQuotes(thirdrelatedword)} 
              </Text>
            </Button>
          </View>
        ): (null)}
        {fourthrelatedword ? (
          <View style={definitionStyles.buttonContainer}>
            <Button rounded warning onPress={() => this.searchFilterFunction(this.removeQuotes(fourthrelatedword))}>
              <Text style = {definitionStyles.buttonText}> 
                {this.removeQuotes(fourthrelatedword)} 
              </Text>
            </Button>
          </View>
        ): (null)}
      </View>
    </View>
    )
  }
}
