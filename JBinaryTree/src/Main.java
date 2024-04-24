import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        final int numElements = 10;
        int[] vals = { 52, 2, 43, 231, 0, 24, 64, 100, 53 };
        BinaryTree<Integer, Comparator<Integer>> root = new BinaryTree<>(vals[0], Integer::compareTo);
        for (int i = 1; i < vals.length; ++i) {
            root.insert(vals[i]);
        }
        BinaryTree.inOrder(root);
    }
}