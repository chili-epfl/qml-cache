import QtQuick 2.5
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QMLCache 1.0

Window {
    visible: true

    width: 640
    height: 480

    Column{
        spacing: 5

        TextField{
            id: keyInput
            text: ""
            placeholderText: "key"
        }

        TextField{
            id: valueInput
            text: ""
            placeholderText: "value"
        }

        Button{
            text: "Write"
            onClicked: {
                QMLCache.write(keyInput.text, valueInput.text);
                keyInput.text = "";
                valueInput.text = "";
            }
        }

        Button{
            text: "Read"
            onClicked: valueInput.text = QMLCache.read(keyInput.text)
        }
    }
}
