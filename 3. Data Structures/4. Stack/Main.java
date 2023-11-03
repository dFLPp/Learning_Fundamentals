// Undo stack
// Aplicação de uma stack na funcionalidade "undo"
// Usaremos uma implementação pronta de stack fornecida pelo Java

import java.util.Stack;

class TextFile {
    private StringBuilder content;

    public TextFile() {
        this.content = new StringBuilder();
    }

    public void append(String content) {
        this.content.append(content);
    }

    public void deleteLastChars(int nLastChars) {
        if (nLastChars > 0 && nLastChars <= this.content.length()) {
            this.content.delete(this.content.length() - nLastChars, this.content.length());
        }
    }

    public String showContent() {
        return this.content.toString();
    }

    public void setContent(String content) {
        this.content = new StringBuilder(content);
    }

    public TextFile createSnapshot() {
        TextFile snapshot = new TextFile();
        snapshot.setContent(this.content.toString());
        return snapshot;
    }
}

class UndoStack {
    private Stack<TextFile> log;

    public UndoStack() {
        this.log = new Stack<>();
    }

    public void saveState(TextFile obj) {
        log.push(obj.createSnapshot());
    }

    public void loadLastSaveState(TextFile file) {
        if (!this.log.isEmpty()) {
            System.out.println("Undoing...");
            TextFile lastState = this.log.pop();
            file.setContent(lastState.showContent());
            System.out.println("Done" + "\n");
        } else {
            System.out.println("No undo operations available");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        TextFile t1 = new TextFile();
        UndoStack s1 = new UndoStack();

        t1.append(("Bananas\nAre\nCool."));
        s1.saveState(t1);
        System.out.println(t1.showContent() + "\n");

        t1.deleteLastChars(5);
        System.out.println(t1.showContent());

        s1.loadLastSaveState(t1);
        System.out.println(t1.showContent());

        s1.loadLastSaveState(t1);
    }
}
