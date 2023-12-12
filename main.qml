import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    title: "Weather Insight"
    width: 600
    height: 800
    visible: true
    color: darkModeSwitch.checked ? "#303030" : "#f0f0f0"

    property double currentTemperature: 0.0
    property string currentWeatherType: ""
    property string currentIconUrl: ""

    Connections {
        target: weatherController
        onDataReceived: {
            //console.log("Retrived current weather data from API:", data);
            var currentWeather = JSON.parse(data);
            currentTemperature = currentWeather.main.temp;
            currentWeatherType = currentWeather.weather[0].main;
            currentIconUrl = "https://openweathermap.org/img/wn/" + currentWeather.weather[0].icon + "@2x.png";
            console.log("Current weather:", currentWeatherType, currentTemperature + " degrees", currentIconUrl);
        }
        onErrorOccurred: {
            console.log("Failed to retrieve current weather data:", error);
        }
    }

    Connections {
        target: forecastController
        onDataReceived: {
            //console.log("Retrived weather forecast data from API:", data);
            var weatherForecast = JSON.parse(data);
            for (var i = 0; i < weatherForecast.list.length; i++) {
                var forecast = weatherForecast.list[i];
                var temperature = forecast.main.temp;
                var weatherType = forecast.weather[0].main;
                var date = new Date(forecast.dt * 1000);
                var day = date.toLocaleDateString("no-NO", { weekday: "long" });
                if (date.getUTCHours() != 12) continue;
                console.log("Weather forecast:", day, weatherType, temperature + " degrees");
                forecastList.model.append({ day: day, temp: temperature + " °C", condition: weatherType });
            }
        }
        onErrorOccurred: {
            console.log("Failed to retrieve weather forecast data:", error);
        }
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 20

        TextField {
            id: cityInput
            placeholderText: "Navn på by"
            placeholderTextColor: darkModeSwitch.checked ? "#fff" : "#000"
            text: "Kongsberg"
            Layout.fillWidth: true
            Layout.margins: 10
            color: darkModeSwitch.checked ? "#fff" : "#000"
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
                    text: currentTemperature + " °C"
                    font.pixelSize: 40
                    color: darkModeSwitch.checked ? "#fff" : "#000"
                }

                Text {
                    id: currentWeather
                    text: currentWeatherType
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
                    Text { text: condition; color: darkModeSwitch.checked ? "#fff" : "#000" }
                    Text { text: temp; color: darkModeSwitch.checked ? "#fff" : "#000" }
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
