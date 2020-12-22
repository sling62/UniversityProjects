// Author: Samantha Ling 
// Date: 23/02/20 
// File Description: styling for Home Screen

import {StyleSheet } from 'react-native';

export default StyleSheet.create({
    appLogo: {
        marginLeft:60
    },
    settingsIcon: {
        fontSize: 35, 
        color: '#FFFFFF', 
        marginTop: 25, 
        marginRight:18
    },
    wordOfTheDayContainer: {
        backgroundColor: "#009999", 
        width:350, 
        height:300, 
        marginLeft:20, 
        borderRadius:20, 
        marginBottom:10,
        marginTop:20
    },
    button: {
        paddingBottom:20, 
        paddingTop:20
    },
    wordOfTheDay: {
        marginLeft:30, 
        marginRight:30,
        marginTop:30,
    },
    wordOfTheDayHeading: {
        fontFamily: "Raleway_Bold",
        fontSize: 28, 
    },
    wordOfTheDayPronunciation: {
        fontFamily: "Raleway_Regular",
        fontSize: 20, 
        marginTop:10
    },
    wordOfTheDayAction: {
        fontFamily: "Raleway_Italic",
        fontSize: 20, 
        marginBottom:20
    },
    wordOfTheDayDefinition: {
        fontFamily: "Raleway_Regular",
        fontSize: 18, 
        marginBottom:20
    },
    wordOfTheDayExample: {
        fontFamily: "Raleway_Italic", 
        color: "#FFFFFF", 
        fontSize: 18,
    }
});