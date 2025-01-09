

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;

import java.awt.*;
import java.awt.event.*;
 
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.text.*;
 
import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeEvent;
 
import java.text.*;

//just a button so far
public class app {


    public static void main(String[] args) {
        JFrame f = new JFrame("A JFrame");
    f.setSize(1200, 900);
    f.setLocation(300,200);
    final JTextArea textArea = new JTextArea(10, 40);
    f.getContentPane().add(BorderLayout.CENTER, textArea);
    final JButton button = new JButton("Click Me");
    f.getContentPane().add(BorderLayout.SOUTH, button);
    button.addActionListener(new ActionListener() {

        @Override
        public void actionPerformed(ActionEvent e) {
            textArea.append("Button was clicked\n");

        }
    });

    f.setVisible(true);

  }
}
