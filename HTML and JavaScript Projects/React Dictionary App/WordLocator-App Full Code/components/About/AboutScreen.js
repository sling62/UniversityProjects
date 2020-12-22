// Author: Samantha Ling 
// Date: 20/02/20 
// File Description: Screen to display app description

import React, { Component } from 'react';
import {View, Text} from 'react-native';
import {screenTitles, aboutInfo} from '../Constants.js' //importing screen text from constants file
import styles from '../Styles.js'; //importing shared app styling

export default class Aboutscreen extends Component {
  render() {
    return (
      <View style = {styles.appStyling}>
        <Text style={styles.heading}> 
          {screenTitles['About']}
        </Text>
        <Text style={styles.bodyText}> 
          {aboutInfo['appDescription']}
        </Text>
        <Text style={styles.bodyText}> 
          {aboutInfo['wordOfTheDayDescription']}
        </Text>
      </View>
    );
  }
}
