// Author: Samantha Ling 
// Date: 20/02/20 
// File Description: Screen to display basic app privacy policy

import React, { Component } from 'react';
import { View, Text } from 'react-native';
import {screenTitles, privacyInfo} from '../Constants.js' //importing screen text from constants file
import styles from '../Styles.js' //importing shared app styling

export default class Privacyscreen extends Component {
  render() {
    return (
      <View style = {styles.appStyling}>
        <Text style={styles.heading}> 
          {screenTitles['Privacy']}
        </Text>
        <Text style={styles.bodyText}> 
          {privacyInfo['appPrivacy']}
        </Text>
        <Text style={styles.bodyText}> 
          {privacyInfo['informationUse']}
        </Text>
      </View>
    )
  }
}
