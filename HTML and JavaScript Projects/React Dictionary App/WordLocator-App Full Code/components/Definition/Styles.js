// Author: Samantha Ling 
// Date: 04/04/20 
// File Description: styling for Definition Screen

import {StyleSheet } from 'react-native';

export default StyleSheet.create({
    container: {
        marginTop:60,
        flex: 1,
        flexDirection: 'row',
        alignItems: 'center',
        justifyContent: 'center',
    },
    buttonContainer: {
        flex: 1,
        margin:20,
    },
    wordContainer: {
        borderBottomWidth: 0,
        paddingBottom:0
    },
    wordHeader: {
        fontFamily: "Raleway_Bold",
        fontSize: 28,
        marginLeft:10, 
        marginTop:20, 
        paddingRight:30
    },
    wordPronunciation: {
        fontFamily: "Raleway_Regular",
        fontSize: 20, 
        marginLeft:30
    },
    wordAction: {
        fontFamily: "Raleway_Italic",
        fontSize: 20, 
        marginLeft:30, 
        marginTop:20
    }, 
    wordDefinition: {
        fontFamily: "Raleway_Regular",
        fontSize: 18, 
        marginLeft:30, 
        marginTop:20, 
        marginRight:10
    },
    wordExample: {
        fontFamily: "Raleway_Italic", 
        color: "gray", 
        fontSize: 18, 
        marginLeft:30, 
        marginTop:5, 
        marginRight:10
    },
    buttonText: {
        fontFamily: "Raleway_Bold", 
        fontSize: 16, 
        marginLeft: 10, 
        textAlign:"center"
    },
    similarHeading: {
        fontFamily: "Raleway_Bold",
        fontSize: 20,
        marginTop:60,
        marginLeft:30, 
    },
    volumeIcon: {
        color:'#000000'
    }
});