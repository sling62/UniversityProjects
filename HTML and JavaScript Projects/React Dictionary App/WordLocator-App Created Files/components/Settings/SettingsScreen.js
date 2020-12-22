// Author: Samantha Ling 
// Date: 20/02/20 
// File Description: Settings directory page, routes to notifications, privacy, support and about screens, as well as allows user to rate app on Google Play Store (NOTE: App has not been published on Google Play Store)

import React, { Component } from 'react';
import { Text, Linking } from 'react-native';
// native base package is installed and Icon, List, ListItem, Content, Left and Right UI position elements are imported, for more information please see: https://docs.nativebase.io/
import { Icon, ListItem, Left, Right, Content, List } from 'native-base'; 
import {screenTitles, versionInfo, forwardIcon} from '../Constants.js' //importing screen text from constants file
import styles from '../Styles.js' //importing shared app styling
import settingsStyles from './Styles.js' //importing styling specific to settings screen

export default class Settingsscreen extends Component {
  render() {
    return (
      <Content style = {styles.appStyling}>
        <Text style={settingsStyles.heading}> 
          {screenTitles['Settings']}
        </Text>
        <List>
          <ListItem button style = {settingsStyles.ListItem} onPress={() => this.props.navigation.navigate('Notifications')}>
            <Left>
              <Text style = {settingsStyles.listText}>{screenTitles['Notifications']}</Text>
            </Left>
            <Right>
              <Icon name={forwardIcon} />
            </Right>
          </ListItem>
          <ListItem button style = {settingsStyles.ListItem} onPress={() => this.props.navigation.navigate('Privacy')}>
            <Left>
              <Text style = {settingsStyles.listText}>{screenTitles['Privacy']}</Text>
            </Left>
            <Right>
              <Icon name={forwardIcon} />
            </Right>
          </ListItem>
          <ListItem button style = {settingsStyles.ListItem} onPress={() => this.props.navigation.navigate('Support')}>
            <Left>
              <Text style = {settingsStyles.listText}>{screenTitles['Support']}</Text>
            </Left>
            <Right>
              <Icon name={forwardIcon} />
            </Right>
          </ListItem>
          <ListItem style = {settingsStyles.ListItem}  onPress={() => Linking.openURL('https://play.google.com')}> 
            <Left>
              <Text style = {settingsStyles.listText}>{screenTitles['RateApp']}</Text>
            </Left>
            <Right>
              <Icon name={forwardIcon} />
            </Right>
          </ListItem>
          <ListItem style = {settingsStyles.ListItem} button onPress={() => this.props.navigation.navigate('About')}>
            <Left>
              <Text style = {settingsStyles.listText}>{screenTitles['About']}</Text>
            </Left>
            <Right>
              <Icon name={forwardIcon} />
            </Right>
          </ListItem>
        </List>
        <Text style={[settingsStyles.listText, settingsStyles.versionText]}> 
          {versionInfo}
        </Text>
      </Content>
    )
  }
}
