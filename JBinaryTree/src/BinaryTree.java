import java.util.Comparator;

public class BinaryTree<T, C extends Comparator<T>> {
    private final T value;
    private final C comparator;
    private BinaryTree<T, C> left;
    private BinaryTree<T, C> right;

    public BinaryTree(T value, C comparator) {
        this.value = value;
        this.comparator = comparator;
        this.left = null;
        this.right = null;
    }

    public T getValue() {
        return value;
    }

    public BinaryTree<T, C> getLeft() {
        return left;
    }

    public BinaryTree<T, C> getRight() {
        return right;
    }

    public void insert(T value) {
        int x = comparator.compare(this.value, value);
        if (x == 0) { return; } // No duplicates.

        if (x < 0) {
            if (right == null) {
                right = new BinaryTree<T, C>(value, comparator);
            } else {
                right.insert(value);
            }
        } else {
            if (left == null) {
                left = new BinaryTree<T, C>(value, comparator);
            } else {
                left.insert(value);
            }
        }
    }

    public static <X, Y extends Comparator<X>> void preOrder(BinaryTree<X, Y> node) {
        System.out.println(node.getValue().toString());
        if (node.getLeft() != null) { preOrder(node.getLeft()); }
        if (node.getRight() != null) { preOrder(node.getRight()); }
    }

    public static <X, Y extends Comparator<X>> void inOrder(BinaryTree<X, Y> node) {
        if (node.getLeft() != null) { inOrder(node.getLeft()); }
        System.out.println(node.getValue().toString());
        if (node.getRight() != null) { inOrder(node.getRight()); }
    }

    public static <X, Y extends Comparator<X>> void postOrder(BinaryTree<X, Y> node) {
        if (node.getLeft() != null) { postOrder(node.getLeft()); }
        if (node.getRight() != null) { postOrder(node.getRight()); }
        System.out.println(node.getValue().toString());
    }
}