// Author: Samantha Ling 
// Date: 20/02/20 
// File Description: Screen for users to get help on the app

import React, { Component } from 'react';
import { View, Text } from 'react-native'; 
import {screenTitles, supportInfo} from '../Constants.js' //importing screen text from constants file
import styles from '../Styles.js' //importing shared app styling

export default class Supportscreen extends Component {
  render() {
    return (
      <View style = {styles.appStyling}>
        <Text style = {styles.heading}> 
          {screenTitles['Support']}
        </Text>
        <Text style={styles.bodyText}> 
          {supportInfo['documentationText']}
        </Text>
        <Text style={[styles.link,styles.bodyText]}> 
          {supportInfo['documentationLink']}
        </Text>
        <Text style={styles.bodyText}> 
          {supportInfo['furtherAssistanceText']}
        </Text>
        <Text style={styles.subheading}> 
          {supportInfo['emailHeader']}
        </Text>
        <Text style={[styles.link,styles.bodyText]}> 
          {supportInfo['email']}
        </Text>
        <Text style={styles.subheading}> 
          {supportInfo['telephoneHeader']}
        </Text>
        <Text style={styles.bodyText}> 
          {supportInfo['headOfficeTelephone']}
        </Text>
        <Text style={styles.bodyText}> 
          {supportInfo['itSupportTelephone']}
        </Text>
      </View>
    )
  }
}