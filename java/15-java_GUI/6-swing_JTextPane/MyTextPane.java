import java.awt.BorderLayout;
import javax.swing.*;
import javax.swing.event.*;

class CaretDemo extends JFrame {
    private JTextArea editor;
    private JTextField status;

    public CaretDemo() {
        setTitle("Caret Demo");
        setSize(500,500);
        setLayout(new BorderLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        editor = new JTextArea();
        editor.addCaretListener(new CaretListener() {
            public void caretUpdate(CaretEvent e) {
                JTextArea editArea = (JTextArea)e.getSource();

                int linenum = 1;
                int columnnum = 1;

                try {
                    int caretpos = editArea.getCaretPosition();
                    linenum = editArea.getLineOfOffset(caretpos);
                    columnnum = caretpos - editArea.getLineStartOffset(linenum);
                    linenum += 1;
                }
                catch(Exception ex) { }
                updateStatus(linenum, columnnum);
            }
        });

        add(editor, BorderLayout.CENTER);
        status = new JTextField();
        add(status, BorderLayout.SOUTH);
        updateStatus(1,1);
    }

    private void updateStatus(int linenumber, int columnnumber) {
        status.setText("第 " + linenumber + " 行, 第 " + columnnumber+" 列  ");
        status.setHorizontalAlignment(JTextField.RIGHT);
    }

    public static void main(String args[]) {
        CaretDemo caretDemoApp = new CaretDemo();
        caretDemoApp.setVisible(true);
    }
}
