// Author: Samantha Ling 
// Date: 14/03/20 
// File Description: Screen to allow a user to search for a word definition (ie. returns search results), for more information please see: https://www.freecodecamp.org/news/how-to-build-a-react-native-flatlist-with-realtime-searching-ability-81ad100f6699/

import React, { Component } from 'react';
//Flatlist is imported to render search results, ActivityIndicator is imported to display loading icon when search results have not yet rendered
import { View, FlatList, ActivityIndicator } from 'react-native'; 
// react native elements package is installed and listItem and SearchBar UI elements are imported, for more information please see: https://react-native-elements.github.io/react-native-elements/docs.html
import { ListItem, SearchBar } from 'react-native-elements'; 
import { searchPlaceholderText, isVisible } from '../Constants.js' //importing screen text from constants file
import searchStyles from './Styles' //importing styling specific to Search Screen


export default class Searchscreen extends Component {
  constructor(props) {
    super(props);

    this.state = {
      loading: false, //state to indicate if search results has loaded
      data: [], //array holder to hold searched word record
      error: null, //error state to indicate error in fetching search results
      showSearch: isVisible['invisible'] //state to hide/display search results (when not loaded/loaded)
    };
    this.arrayholder = []; //temporary array holder to hold JSON objects fetched from Firebase
  }

  componentDidMount() {
    this.makeRemoteRequest();
  }

  makeRemoteRequest = () => {
    const url = `https://wordlocator-app.firebaseio.com/.json`; //url to .json script in Firebase
    this.setState({ loading: true }); 
  
    fetch(url)
      .then(res => res.json())
      .then(res => {
        this.setState({
          data: res.results, 
          error: res.error || null, 
           //once json script is fetched, loading state is set to false so search results can be displayed 
          loading: false,
        });
        //once results are fetched, this is placed in an array where each array element is a word record
        this.arrayholder = res.results; 
      })
      .catch(error => {
        this.setState({ error, loading: false }); 
      });
  };

  //renders seperator (line) for words in search results (could not move styling to seperate stylesheet due to display state value)
  renderSeparator = () => {
    return (
      <View
        style={{
          height: 1,
          width: '93%',
          backgroundColor: '#CED0CE',
          marginLeft: '3%',
          display: this.state.showSearch
        }}
      />
    );
  };
  
  //search function which takes as a parameter the searched for word (as inputted in search bar)
  searchFilterFunction = text => {
    //filters json data to get searched for word record
    const newData = this.arrayholder.filter(item => {
      const itemData = `${item.definition.name.toUpperCase()} ${item.definition.description.toUpperCase()}`;
      const textData = text.toUpperCase();
      return itemData.indexOf(textData) > -1;
    });

    this.setState({
        value: text,
        showSearch: isVisible['visible'], //allows search results to be visible 
        //sets the word record to data field in class state, to be able to be accessed from render method
        data: newData, 
    });

    //checks to see if the search bar input is empty, if so, no search results should be displayed
    if(text == '') {
      this.setState({showSearch: isVisible['invisible']})
    }
  };
    
  //function to render the header (ie. search bar (+ styling parameters) from react-native elements)
  renderHeader = () => {
    return (
      <SearchBar
        placeholder= {searchPlaceholderText}
        containerStyle = {searchStyles.searchContainer}
        lightTheme
        searchIcon={{ size: 24 }}
        onChangeText={text => this.searchFilterFunction(text)}
        autoCorrect={false}
        value={this.state.value}
      />
    );
  };
    
  render() {
    //renders ActivityIndicator in case search results is still loading
    if (this.state.loading) {
      return ( 
        <View style={searchStyles.loading}>
          <ActivityIndicator /> 
        </View>
      );
    }
    //renders search results in the form of a react-native Flatlist
    return (
      <View>
        <FlatList
          data={this.state.data}
          renderItem={({ item }) => (
            <ListItem button onPress={() => this.props.navigation.navigate('Definition', {
              name: item.definition.name,
              definition: item.definition.description,
              pronunciation: item.definition.pronunciation,
              action: item.definition.action,
              example: item.definition.example, 
              otherdefinition: item.definition.otherdescription,
              otherexample: item.definition.otherexample,
              firstrelatedword: item.definition.firstrelatedword,
              secondrelatedword: item.definition.secondrelatedword,
              thirdrelatedword: item.definition.thirdrelatedword,
              fourthrelatedword: item.definition.fourthrelatedword,
              audiopath: item.definition.audiopath
            })}
            title={`${item.definition.name}`}
            subtitle={item.definition.description}
            style={{borderBottomColor:'#FFFFFF', display:this.state.showSearch}}
            />
          )}
          keyExtractor={item => item.definition.name}
          ItemSeparatorComponent={this.renderSeparator}
          ListHeaderComponent={this.renderHeader}
        />
      </View>
    )
  }
}