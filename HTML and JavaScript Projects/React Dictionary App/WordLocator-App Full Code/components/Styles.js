// Author: Samantha Ling 
// Date: 14/03/20 
// File Description: shared styling for different components/screens

import {StyleSheet } from 'react-native';

export default StyleSheet.create({
    appStyling: {
        marginLeft:20, 
        marginTop:20, 
        marginBottom:5,
        marginRight:20
    },
    heading: {
        fontFamily: "Raleway_Bold",
        fontSize: 32,
    },
    subheading: {
        fontFamily: "Raleway_Bold",
        fontSize: 18
    },
    bodyText: {
        fontFamily: "Raleway_Regular",
        fontSize: 18,
        marginTop:20,
        marginBottom: 10
    },
    singleListItem: {
        borderBottomColor: '#FFFFFF'
    },
    link: {
        textDecorationLine:'underline',
        color:'#0000FF',
        marginBottom:20
    },
    appLogo: {
        width: 200, 
        height: 110, 
    },
    searchContainer: {
        width: 415, 
        height: 60, 
        backgroundColor: '#012060'
    },
    searchBar: {
        width: 390, 
        height: 55, 
        backgroundColor: '#012060', 
        marginLeft:10, 
        marginRight:5, 
        paddingTop:10
    },
    searchBox: {
        backgroundColor: '#BDC6CF'
    }, 
    search: {
        color: '#86939E' 
    },
    searchPlaceholder : {
        marginRight:260, 
        fontSize: 18
    }
});