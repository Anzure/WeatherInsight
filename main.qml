import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    title: "Weather Insight"
    width: 600
    height: 800
    visible: true
    color: darkModeSwitch.checked ? "#303030" : "#f0f0f0"

    ColumnLayout {
        anchors.fill: parent
        spacing: 20

        TextField {
            id: cityInput
            placeholderText: "Navn på by"
            placeholderTextColor: darkModeSwitch.checked ? "#fff" : "#000"
            Layout.fillWidth: true
            Layout.margins: 10
            color: darkModeSwitch.checked ? "#fff" : "#000"
            //background: Rectangle {
            //    color: "transparent"
            //    border.color: darkModeSwitch.checked ? "#f0f0f0" : "#303030"
            //    radius: 8
            //}
        }

        Button {
            id: searchButton
            text: "Vis værdata"
            Layout.fillWidth: true
            Layout.margins: 10
        }

        Rectangle {
            id: currentWeatherContainer
            width: parent.width
            height: 200
            color: darkModeSwitch.checked ? "#505050" : "#a3c9f4"
            Layout.fillWidth: true

            Column {
                anchors.centerIn: parent
                spacing: 5

                Text {
                    id: currentTemp
                    text: "11°C"
                    font.pixelSize: 40
                    color: darkModeSwitch.checked ? "#fff" : "#000"
                }

                Text {
                    id: currentWeather
                    text: "Regnvær"
                    font.pixelSize: 20
                    color: darkModeSwitch.checked ? "#fff" : "#000"
                }
            }
        }

        ListView {
            id: forecastList
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: ListModel {
                ListElement { day: "Mandag"; temp: "-5°C"; condition: "Overskyet" }
                ListElement { day: "Tirsdag"; temp: "-13°C"; condition: "Sol" }
                ListElement { day: "Onsdag"; temp: "-8°C"; condition: "Snøvær" }
            }
            delegate: Rectangle {
                width: forecastList.width
                height: 50
                color: darkModeSwitch.checked ? "#505050" : "#d3e0ea"

                Row {
                    anchors.verticalCenter: parent.verticalCenter
                    spacing: 20
                    anchors.left: parent.left
                    anchors.leftMargin: 20

                    Text { text: day; color: darkModeSwitch.checked ? "#fff" : "#000" }
                    Text { text: temp; color: darkModeSwitch.checked ? "#fff" : "#000" }
                    Text { text: condition; color: darkModeSwitch.checked ? "#fff" : "#000" }
                }
            }
        }

        Switch {
            id: darkModeSwitch
            text: "Dark Mode"
            Layout.alignment: Qt.AlignRight
            Layout.margins: 10
        }
    }
}
