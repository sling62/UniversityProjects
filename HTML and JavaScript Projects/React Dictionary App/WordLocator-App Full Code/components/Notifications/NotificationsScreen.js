// Author: Samantha Ling 
// Date: 22/02/20 
// File Description: Screen to toggle (through checkbox) word of the day notifications (NOTE:Firebase implementation to display in app notifications had not been implemented yet)

import React, { Component } from 'react';
import { View, Text, Alert } from 'react-native';
// native base package is installed and ListItem, Left and Right UI position elements are imported, for more information please see: https://docs.nativebase.io/
import { ListItem, Left, Right} from 'native-base'; 
// react native elements package is installed and checkbox UI element is imported, for more information please see: https://react-native-elements.github.io/react-native-elements/docs.html
import { CheckBox } from 'react-native-elements' 
import {screenTitles, notificationItemText} from '../Constants.js' //importing screen text from constants file
import styles from '../Styles.js'

export default class Notificationsscreen extends Component {

  constructor(props) {
    super(props);

    this.state = {
      isChecked: false, //value of checkbox, set to false (unchecked) by default
    };
  }

  //sets checkbox state (isChecked) depending on user selection on warning message
  handleCheckBoxPress = () => {
    return (
      //alerts user of notification (checkbox) value change
      Alert.alert( 
        'Notification Alert',
        'Are you sure you want to change your word of the day notifications?',
        [
          {text: 'Yes', onPress: () => this.setState({ isChecked: !this.state.isChecked})}, //changes checkbox value
          {text: 'Cancel'}, //keeps checkbox value
        ],
      )
    );
  }

  render() {
    return (
      <View style = {styles.appStyling}>
        <Text style={styles.heading}> 
          {screenTitles['Notifications']}
        </Text>
        <ListItem style = {styles.singleListItem}>
          <Left>
            <Text style = {styles.bodyText}>
              {notificationItemText}
            </Text>
          </Left>
          <Right>
            <CheckBox 
              checked={this.state.isChecked}
              onPress={()=> this.handleCheckBoxPress()}
              size = {34}
              checkedColor = {'#012060'}
            />
          </Right>
        </ListItem>
      </View>
    )
  }
}