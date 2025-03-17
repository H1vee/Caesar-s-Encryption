import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window

ApplicationWindow {
    id: root
    visible: true
    width: 800
    height: 600
    minimumWidth: 600
    minimumHeight: 400
    title: "Афінний шифр Цезаря"
    color: "#f9f9f9"

    // Custom properties
    property color primaryColor: "#3F51B5"
    property color accentColor: "#FF4081"
    property color textColor: "#424242"
    property color backgroundColor: "#FFFFFF"
    property color borderColor: "#E0E0E0"

    // Custom button style
    Component {
        id: buttonStyle
        Button {
            id: control
            contentItem: Text {
                text: control.text
                font.pixelSize: 14
                color: control.down ? "#FFFFFF" : "#FFFFFF"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            background: Rectangle {
                radius: 4
                color: control.down ? Qt.darker(control.property) : control.property
                border.width: 0

                Behavior on color {
                    ColorAnimation { duration: 150 }
                }
            }
        }
    }

    // Content
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 20

        // Header - without shadow effect for compatibility
        Rectangle {
            Layout.fillWidth: true
            height: 60
            color: root.primaryColor
            radius: 6

            RowLayout {
                anchors.fill: parent
                anchors.margins: 10

                Item { width: 32 } // Placeholder for icon

                Label {
                    Layout.fillWidth: true
                    text: "Афінний шифр Цезаря"
                    font.pixelSize: 22
                    font.bold: true
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }

        // Main content area - without shadow effect
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.leftMargin: 10
            Layout.rightMargin: 10
            color: root.backgroundColor
            radius: 6
            border.color: "#DDDDDD"
            border.width: 1

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 20
                spacing: 15

                // Input section
                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 5

                    Label {
                        text: "Вхідний текст:"
                        font.pixelSize: 14
                        font.bold: true
                        color: root.textColor
                    }

                    ScrollView {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 120
                        clip: true

                        TextArea {
                            id: inputText
                            placeholderText: "Введіть текст для шифрування/дешифрування"
                            wrapMode: TextEdit.Wrap
                            selectByMouse: true
                            font.pixelSize: 14
                            color: root.textColor

                            background: Rectangle {
                                color: "#F5F5F5"
                                border.color: root.borderColor
                                border.width: 1
                                radius: 4
                            }
                        }
                    }
                }

                // Parameters section
                Rectangle {
                    Layout.fillWidth: true
                    height: 80
                    color: "#F0F4FF"
                    radius: 4
                    border.color: "#D0D9FF"
                    border.width: 1

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 10
                        spacing: 5

                        Label {
                            text: "Параметри шифру:"
                            font.pixelSize: 14
                            font.bold: true
                            color: root.textColor
                        }

                        RowLayout {
                            Layout.fillWidth: true
                            spacing: 20

                            // Key A
                            RowLayout {
                                spacing: 10

                                Label {
                                    text: "Ключ a:"
                                    font.pixelSize: 14
                                    color: root.textColor
                                }

                                Rectangle {
                                    width: 80
                                    height: 32
                                    color: "#FFFFFF"
                                    radius: 4
                                    border.color: root.borderColor
                                    border.width: 1

                                    TextField {
                                        id: keyA
                                        anchors.fill: parent
                                        anchors.margins: 2
                                        horizontalAlignment: TextInput.AlignHCenter
                                        placeholderText: "a"
                                        validator: IntValidator {bottom: 1}
                                        selectByMouse: true
                                        font.pixelSize: 14
                                        background: null
                                    }
                                }
                            }

                            // Key B
                            RowLayout {
                                spacing: 10

                                Label {
                                    text: "Ключ b:"
                                    font.pixelSize: 14
                                    color: root.textColor
                                }

                                Rectangle {
                                    width: 80
                                    height: 32
                                    color: "#FFFFFF"
                                    radius: 4
                                    border.color: root.borderColor
                                    border.width: 1

                                    TextField {
                                        id: keyB
                                        anchors.fill: parent
                                        anchors.margins: 2
                                        horizontalAlignment: TextInput.AlignHCenter
                                        placeholderText: "b"
                                        validator: IntValidator {bottom: 0; top: 25}
                                        selectByMouse: true
                                        font.pixelSize: 14
                                        background: null
                                    }
                                }
                            }

                            Item { Layout.fillWidth: true } // Spacer
                        }
                    }
                }

                // Action buttons
                RowLayout {
                    Layout.fillWidth: true
                    spacing: 15

                    // File operations
                    Button {
                        Layout.preferredHeight: 36
                        property color property: "#607D8B"
                        text: "Відкрити файл"

                        background: Rectangle {
                            radius: 4
                            color: parent.down ? Qt.darker(parent.property) : parent.property

                            Behavior on color {
                                ColorAnimation { duration: 150 }
                            }
                        }

                        contentItem: Text {
                            text: parent.text
                            font.pixelSize: 14
                            color: "#FFFFFF"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }

                        onClicked: affineCipher.openFile()
                    }

                    Button {
                        Layout.preferredHeight: 36
                        property color property: "#607D8B"
                        text: "Зберегти файл"

                        background: Rectangle {
                            radius: 4
                            color: parent.down ? Qt.darker(parent.property) : parent.property

                            Behavior on color {
                                ColorAnimation { duration: 150 }
                            }
                        }

                        contentItem: Text {
                            text: parent.text
                            font.pixelSize: 14
                            color: "#FFFFFF"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }

                        onClicked: affineCipher.saveEncryptedFile()
                    }

                    Item { Layout.fillWidth: true } // Spacer

                    // Cipher operations
                    Button {
                        Layout.preferredHeight: 36
                        property color property: root.primaryColor
                        text: "Зашифрувати"

                        background: Rectangle {
                            radius: 4
                            color: parent.down ? Qt.darker(parent.property) : parent.property

                            Behavior on color {
                                ColorAnimation { duration: 150 }
                            }
                        }

                        contentItem: Text {
                            text: parent.text
                            font.pixelSize: 14
                            color: "#FFFFFF"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }

                        onClicked: {
                            if (keyA.text === "" || keyB.text === "") {
                                messageDialog.text = "Будь ласка, введіть ключі a та b"
                                messageDialog.open()
                            } else {
                                resultText.text = affineCipher.encrypt(inputText.text, keyA.text, keyB.text)
                            }
                        }
                    }

                    Button {
                        Layout.preferredHeight: 36
                        property color property: root.accentColor
                        text: "Розшифрувати"

                        background: Rectangle {
                            radius: 4
                            color: parent.down ? Qt.darker(parent.property) : parent.property

                            Behavior on color {
                                ColorAnimation { duration: 150 }
                            }
                        }

                        contentItem: Text {
                            text: parent.text
                            font.pixelSize: 14
                            color: "#FFFFFF"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }

                        onClicked: {
                            if (keyA.text === "" || keyB.text === "") {
                                messageDialog.text = "Будь ласка, введіть ключі a та b"
                                messageDialog.open()
                            } else {
                                resultText.text = affineCipher.decrypt(inputText.text, keyA.text, keyB.text)
                            }
                        }
                    }
                }

                // Result section
                ColumnLayout {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    spacing: 5

                    RowLayout {
                        Layout.fillWidth: true

                        Label {
                            text: "Результат:"
                            font.pixelSize: 14
                            font.bold: true
                            color: root.textColor
                        }

                        Item { Layout.fillWidth: true } // Spacer

                        Button {
                            text: "Копіювати"
                            flat: true
                            font.pixelSize: 12

                            onClicked: {
                                clipboard.setText(resultText.text)
                                copyTooltip.open()
                            }

                            ToolTip {
                                id: copyTooltip
                                text: "Скопійовано"
                                timeout: 1000
                            }
                        }
                    }

                    ScrollView {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        clip: true

                        TextArea {
                            id: resultText
                            readOnly: true
                            wrapMode: Text.Wrap
                            selectByMouse: true
                            text: "Результат з'явиться тут"
                            font.pixelSize: 14
                            color: root.textColor

                            background: Rectangle {
                                color: "#F5F5F5"
                                border.color: root.borderColor
                                border.width: 1
                                radius: 4
                            }
                        }
                    }
                }
            }
        }

        // Status bar
        Rectangle {
            Layout.fillWidth: true
            height: 24
            color: "#EEEEEE"
            radius: 3

            RowLayout {
                anchors.fill: parent
                anchors.margins: 4
                spacing: 10

                Label {
                    text: "Статус: Готовий"
                    font.pixelSize: 12
                    color: "#666666"
                }

                Item { Layout.fillWidth: true } // Spacer

                Label {
                    text: "© 2025 Афінний шифр"
                    font.pixelSize: 12
                    color: "#666666"
                }
            }
        }
    }

    // Dialog for messages
    Dialog {
        id: messageDialog
        title: "Повідомлення"
        standardButtons: Dialog.Ok
        property alias text: messageLabel.text

        anchors.centerIn: parent
        width: 300

        Label {
            id: messageLabel
            anchors.fill: parent
            wrapMode: Text.Wrap
        }
    }
}
